#include<iostream>
#include<queue>
using namespace std ; 
class node{
    public: 
    int data ; 
    node* left ; 
    node* right ; 

    // default constructor calling 
    node(int d ){
        data =d ; 
        left = right = NULL;
    }

} ; 

// function for creation of tree for the level wise input
node* levelwise(){
    int data ; 
    cin>> data ;
    // base case 
    if ( data == -1 ){
        return NULL;

    }
    node* root = new node(data) ;
    // creation of queue for level printing 
    queue <node* > q ; 
    q.push(root ) ;

    while(!q.empty()){
     node* f = new node(data) ; 
     q.pop() ; 
     cout<<"Enter the child of"<<f->data ; 
     int l , r  ;
     cin>>l >> r ; 
     if (l!= - 1){
        f ->left = new node(l) ; 
        q.push(root ->left) ;
        

     }
     if (r!=-1 ){
        f ->right = new node(r) ;
        q.push(root ->right ) ;

     }
    }
     return root ;
}
// function for printing the preOrder Sequence 
void preOrder (node* root ){
    if (!root ){
        return ;
    }
    cout<<root ->data<<" ";
    preOrder(root->left) ;
    preOrder(root->right);
}
int main (){
    node* root = levelwise() ;
     cout<<"Preorder Sequence of given tree is :";
     preOrder(root );

    return 0 ; 
}