#include<bits/stdc++.h>
 using namespace std ; 

 class Node{
    public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    // default constructor 

    Node(int d ){
        this ->data =d ; 
        this->left = NULL  ; 
        this->right = NULL ; 
    }

 } ; 

 Node*insertNodeBST(Node* root  , int d ){
    if (root == NULL ){
        root = new Node(d ) ; 
        return root ; 
    }

    else if (root ->data < d ){
        root ->right = insertNodeBST(root->right , d ) ; 
        return root ; 
    }
    else {
        root ->left = insertNodeBST(root->left ,d ) ; 
        return root ; 
    }

    return root ;
 }
 void takeInput (Node* &root ){
    int data ; 
    cout<<"Enter data for the bst nodes : "<<endl ; 
    cin>> data ; 

    while (data!=-1 ){
        root = insertNodeBST(root , data ) ; 
        cin>> data ; 
    }
    return ;
 }

 void levelOrderTraversal (Node* root ){
    queue<Node*> q ; 
    q.push(root); 

    while (!q.empty()){
       int level = q.size(); 
       for (int i=0 ;i<level;i++){
         Node* frontNode = q.front(); 

        q.pop()  ; 

        cout<<frontNode->data<<" " ; 

        if (frontNode->left ) {
            q.push(frontNode->left);
        }

        if (frontNode->right){
            q.push(frontNode->right    );
            
        }
       }
       cout<<endl;
    }
 }
// function for merge 2  binary search tree to single binary search treee 
void inorder(Node* root , vector<int>&ans ){
    if (!root )return ; 
    inorder(root->left , ans ) ; 
    ans.push_back(root->data) ; 
    inorder(root->right, ans ) ; 

    return ;
}

vector<int> merge2sortedArray(vector<int> a , vector<int > b){
    int n = a.size() ; 
    int m = b.size() ; 

    // 2 pointer technique and simple comparison 
    int i =0 , j=0; 
    vector<int> ans ; 
    while(i<n and j<m ){
         if (a[i]<b[j]){
            ans.push_back(a[i]) ;
            i++ ; 
         }
         else{
            ans.push_back(b[j]) ; 
            j++ ;
         }
    }


//  if some of the array still gets remained in any of the array 
    while  (a[i]<b[j]){
                ans.push_back(a[i]) ;
                i++ ; 
            }


         while(j<m){
            ans.push_back(b[j]) ; 
            j++ ;
         }

return ans;
        
}

Node* s2BST(vector<int>&in , int s , int e){
    // base case 
    if (s>e )return NULL ; 

    int mid = (s+e)/2 ; 

    Node* root = new Node(in[mid]); 
    root ->left = s2BST(in, s , mid -1 ) ; 
    root ->right = s2BST(in,  mid + 1 , e  ) ;
    return root ; 
}
// approach 1: 
Node*  mergeBST1 (Node* root1 , Node* root2 ){
// concept : find inorder traveral of both bst , apply merge 2 sorted array ,than sorted array to bst 
// time : O(n+m) , space : O(n+m )

    // step 1 : Store inorder traveral of both the trees 
    vector<int> a ; 
    inorder(root1 , a ) ;
    vector<int> b; 
    inorder(root2,b ) ;


    // step 2 : find the merge 2 sorted array concept 
    vector<int> ans = merge2sortedArray (a , b ) ;

    // step 3 : create bst from the sorted array 
    return s2BST(ans ,0 , ans.size()-1 ) ; 




}




//**********Approach 2 : optmised approach : time:O(h1 + h2 )


    // function for converting the bst to double link list 

void convert(Node* root , Node* &head ){
    // concept : Recursion , time : O(n) , space :O(h)

    // base case 
    if (!root )return  ; 

    // step 1 : convert the rightsubtree to sorted DLL 
    convert(root->right , head) ; 

    // step 2 : make the connection between right head and root 
    root->right = head ; // root right is connected to head of right sorted dll(from right subtree)

    // Step3 : make rightHead connection with root (for shifing the pointers )
    if (head != NULL ){
         head->left = root ; 
    }


    // step 4 : shift the pointers (left side )
    head = root ; 

    convert(root->left , head) ; 


    // here new head of link list will automatically change to its position 


}
Node* BST2DLL(Node* root ){

    Node* head = NULL ; // head of new sorted link list 
    convert(root, head);

    // step 2 : make the left pointers of nodes to nULL 
    Node* temp = head ;
    while (temp){

        temp->left = NULL ;
        temp = temp->right ;
    }

    return head ;

}

    // for merging the two doubly link list 

Node* merge2DLL(Node* head1 , Node* head2 ){
    // concept : recursion , time : Omax (h1 , h2 ), space : max(H1 , H2 )
    if (head1 == NULL and head2== NULL )return NULL  ; 
    if (head1== NULL )return head2 ; 
    if(head2== NULL )return head1 ; 


    // recursive case

    // step 1 : creation of a dummy pointer 
    Node* temp = NULL ; // this pointer will always point to smaller value 
    if (head1->data<= head2->data){
        temp = head1  ;
        temp->right = merge2DLL(temp->right , head2);

    }
    else{

        temp = head2 ; 
       temp->right =  merge2DLL(head1 , temp->right) ;


    }


    return temp ;


}

    // for converting the sorted LL to bst 

    // function for the sorted link list to the height balanced bst 

int countNodes(Node* head ){

    int cnt =0; 
    while (head ){

        cnt++ ;
        head = head->right ;
    }

    return cnt ;

}

Node*  LL2BST(Node* head , int n ){

    // base case 
    if (head  == NULL || n<= 0 )return NULL ; 


    // step 1 : create the right subtree 
    Node* leftCheck = LL2BST(head , n/2 ) ; 


    // create root node 
    Node* root = head ; 

    // attach the left subtree 
    root->left =leftCheck ; 

    head = head ->right ;

    Node* rightCheck = LL2BST(head , n-n/2 -1 ) ; 

    root-> right = rightCheck ;

    return root ;

}
Node* sortedLL2BST(Node* head ){

    // concept : Recursion , Node count 

    // step 1 : find the number of nodes in the ll 
    int n = countNodes(head);

    return LL2BST(head , n ) ; 



    // step 2 : create tree based on the nodes value 
}
Node* merge2BST2 (Node* root1 , Node* root2 ){
    // time : O(n+m ), space : O(h1 + h2 : recursive stack spaces of first and second tree )
    // concept : changing of pointers : link list , without use of storing the inorder traversal

    // step 1: convert the bst to the sorted link list (for both lists )
    root1 = BST2DLL(root1 ) ; 
    root2 = BST2DLL(root2) ;

    // step2 : merge 2 sorted link list 
    Node* head = merge2DLL(root1 , root2) ; // head of merged 2 sorted link 


    // step 3 : convert  the sorted linklist to balanced bst 

    return sortedLL2BST(head);




}
 int main ()
{

    Node* root1 = NULL  ; 
    Node* root2  = NULL  ; 

    takeInput(root1) ; // 5 3 6 2 4 -1 
    takeInput(root2); //2 1 3 7 6 -1 
    levelOrderTraversal(root1); 
    cout<<endl;
    levelOrderTraversal(root2); 
    cout<<endl;


    // Node* nr = mergeBST1(root1 , root2); 
    // levelOrderTraversal(nr);

    cout<<"printing level order after merging trees : "<<endl;
    Node* nr2 = mergeBST1(root1 , root2); 
    levelOrderTraversal(nr2);

    // 
    return 0 ; 
}
/*
article : 
codestudio : https://www.codingninjas.com/studio/problems/merge-two-bsts_920474?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf  (done )
interview bit : 
gfg : https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1 (rme )
leetcode : https://leetcode.com/problems/binary-search-tree-iterator/  (rem )

*/