#include<bits/stdc++.h>
using namespace std ; 

// question : Create a binary tree using the given inorder and preorder traversal and after creating the binary tree , print the post order traversal 

class node{

    public : 
    int data ; 
    node* left ; 
    node* right ; 

// default constructor 

    node(int d ){
        this -> data =d ; 
        this->left   = NULL ; 
        this->right = NULL ;

    }
};

// function for taking the input of the tree in the level order traverse 
void buildLevelwiseTree(node* &root ){
    int data ; 

    cout<<"Enter the data for the root node: "<<endl;
    cin>> data ; 

    if (data !=-1 ){
        root = new node(data); 

    }
    else{
        root= NULL ; 
        return ; 
    }

    // input for the child nodes 

    queue<node*> q ; 
    q.push(root) ; 

    while (!q.empty()){
        node* frontNode = q.front () ; 
        q.pop() ; 

        int leftData ; 
        
        cout<<"Enter the data for the left of "<<frontNode->data <<endl  ; 
        cin>>leftData ; 
        
        if (leftData!= -1 ){
            frontNode->left  = new node(leftData);
            q.push(frontNode->left) ;
        }

        // right child 
        int rightData ; 
        cout<<"Enter the data for the right of "<<frontNode->data <<endl ;
        cin>>rightData ;
        if (rightData!= -1 ){
            frontNode->right   = new node(rightData);
            q.push(frontNode->right ) ;
        }
    }
    return ; 
}


// function for printing the preorder traversal 
void preorder (node* root , vector<int>&ans ){
    // node left , right 
    if (!root )return ; 
    ans.push_back(root->data);
    preorder(root->left, ans ) ;
    preorder(root->right ,ans );


}
vector<int> pre(node* root ){
    vector<int> ans ; 
    if (!root )return ans ;

    preorder(root, ans ); 
    return ans ;

}

// function for printing the inorder traversal 

void inorder(node*root , vector<int>&ans ){
    //left , rootvalue , right 
    // base case 
    if (!root )return ; 
    inorder(root->left  ,ans ) ;
    ans.push_back(root->data);
    inorder(root->right, ans) ;





}
vector<int > in  (node* root ){
    vector<int> ans ; 
    if (!root) return ans ;
    inorder(root, ans); 
    return ans ;  



}


//**********function for creating tree from the preorder and inorder traversal 
int findPosition (vector<int>in , int element , int n ){

    for (int i=0 ;i<n ;i++){
        if (in[i]== element) {
            return i ;
        }
    }
    return -1 ;
}

node* solve(vector<int>pre , vector<int> in, int n , int &index , int inorderStart , int inorderEnd ){

    // base case 
    if (index>=n|| inorderStart> inorderEnd){
        return  NULL ;
    }

    int element = pre[index ++ ]; 

    // create node corresponding to elment
    node* root  = new node(element);

    int position = findPosition(in, element , n );

    // call for left and right child 
    root->left = solve(pre, in , n , index , inorderStart , position-1 ) ;
    root->right = solve(pre  , in , n , index , position+ 1, inorderEnd);

    return root ;
}

node* createTreePreIn(vector<int>pre , vector<int> in ){
    int  n = pre.size() ; 
    int preorderIndex =0 ; 
   node* root =  solve(pre , in , n , preorderIndex, 0 , n-1 ); 
   return root ; 



}

// functino for printing the postOrder Traversal 
void post(node* root ){
    if (!root )return ; 
    post(root->left) ; 
    post(root->right) ; 
    cout<<root->data<<" ";
}

int main (){
    node* root ; 
    buildLevelwiseTree(root) ;//1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

     vector<int>preOrder = pre(root);
     vector<int> inOrder  = in(root);

     node* n = createTreePreIn(preOrder , inOrder );

     // for verification 
     post(root) ; 
     cout<<endl;
     post(n);
     



    return  0 ; 
}
/*
code studio : https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-preorder-traversal_920539 (rem)
leetcode : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ (done )
gfg: https://practice.geeksforgeeks.org/problems/construct-tree-1/1 (done )
interbiew btit ; 


*/