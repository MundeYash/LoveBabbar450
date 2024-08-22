#include<iostream>
using namespace std ;
 class node{
     public:
     int data ; 
     node* left ; 
     node* right ; 
     node(int d){
        data =d ; 
        left = right = NULL;
     }

 }  ; 
 // function creation for insertion of binary search tree 
 node* insertBST(node* root , int d){
    if (!root ){
         root = new node(d) ;
        return  root ;
    }
    // condition 
    if (root ->data >=d){
        root ->left = insertBST(root ->left , d) ; 
    }
    else{
        root ->right = insertBST(root ->right , d) ; 
    }
     return root ;
 }
 // function for creation of Binary search tree 
 node* createBST(){
    int data ; 
    cin>>data ; 
    if (data== -1){
        return NULL;
    }
    node* root = NULL ; 
    while (data != -1){
        root = insertBST(root,data);
        cin>>data ;
    }
     return root ;
 }
 // for checking our tree is created sucessfully 
 void preOrder (node* root ){
    if (!root ){
        return ;
    }
     cout<<root->data <<" " ;
     preOrder(root->left) ;
     preOrder(root->right) ;
 }
 // function for printing tree nodes value in a range 
 void printRange (node* root  , int k1 , int k2 ){
    if(!root){
        return ;
    }
     printRange(root->left , k1 , k2 ) ; 
      if (root ->data >= k1 and root ->data<= k2 ){
        cout<<root->data <<" ";
      }
      printRange(root->right , k1 , k2) ;

 }
int main (){
    node* root = createBST() ;
     cout<<"This is for Preorder Traversal :" ;
     preOrder(root) ; cout<<endl;

 printRange(root  ,2, 10) ; cout<<endl  ; 
     cout<<"\nMast chalra h \n ";
    return 0 ;
    //8 3 10 1 6 14 4 7 13 -1
}