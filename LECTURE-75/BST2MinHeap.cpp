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
        this ->left =NULL ; 
        this ->right = NULL ;
    }
}; 

void inorder (Node* root , vector<int>&in ){
    if (!root )return ; 
    inorder(root->left , in) ; 
    in.push_back(root ->data ) ; 
    inorder(root->right , in ) ; 

}
void preorder (Node* root , int &index , vector<int> &in){
    // base case 
    if (!root )return ;
    root ->data = in[index ++ ] ;
    preorder(root->left , index , in ) ; 
    preorder(root->right , index , in  );

}
//Question (BST to Min heap ) : given a binary search tree with node val> left child and node val < right child and we ne convert this binary search tree to min heap tree where node val < leftchild and node val < right child 

Node* BST2MinHeap(Node* root ){
    // step 1 : find the inorder traversal of bst (sorted form input value is needed )
    vector<int> in ; 
    inorder (root , in) ;

    // step 2 : traverse the tree in the preorder format and just add the sorted values to create new tree 
    
}
int main (){
    // create the tree and print 

    return 0 ; 
}

/*
code studio : https://www.codingninjas.com/studio/problems/bst-to-min-heap_975371?leftPanelTab=1  (done)
gfg : 
leet code : 
interview bit : 
*/