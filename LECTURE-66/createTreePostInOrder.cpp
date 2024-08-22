#include<bits/stdc++.h>
using namespace std ; 

// question : Create a binary tree using the given inorder and postorder traversal and after creating the binary tree , print the pre order traversal 

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
void preorder (node* root ){
    // node left , right 
    if (!root )return ; 
    cout<<root->data <<" ";
    preorder(root->left) ;
    preorder(root->right  );


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

node* solve(vector<int>post , vector<int> in, int n , int &index , int inorderStart , int inorderEnd ){

    // base case 
    if (index<0|| inorderStart> inorderEnd){
        return  NULL ;
    }

    int element = post[index -- ]; 

    // create node corresponding to elment
    node* root  = new node(element);

    int position = findPosition(in, element , n );

    // call for left and right child 

     root->right = solve(post , in , n , index , position+ 1, inorderEnd);
    root->left = solve(post, in , n , index , inorderStart , position-1 ) ;
   

    return root ;
}

node* createTreePostIn(vector<int>post , vector<int> in ){
    int  n = post.size() ; 
    int postorderIndex =n-1  ; 
   node* root =  solve(post , in , n , postorderIndex, 0 , n-1 ); 
   return root ; 



}

// functino for printing the postOrder Traversal 
void postorder (node* root, vector<int>&ans  ){
    if (!root )return ; 
    postorder(root->left, ans) ; 
    postorder(root->right , ans ) ; 

    ans.push_back(root->data); 
    
}

vector<int> post(node* root ){
    vector<int> ans ; 
    if (!root )return ans ;

    postorder(root, ans ); 
    return ans ;

}
int main (){
    node* root ; 
    buildLevelwiseTree(root) ;//1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

     vector<int>postOrder = post(root);
     vector<int> inOrder  = in(root);

     node* n = createTreePostIn(postOrder , inOrder );

     // for verification 
     preorder(root) ; 
     cout<<endl;
     preorder(n);
     



    return  0 ; 
}
/*
code studio : https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-preorder-traversal_920539 (rem)
leetcode : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ (done )
gfg: https://practice.geeksforgeeks.org/problems/construct-tree-1/1 (done )
interbiew btit ; 


*/