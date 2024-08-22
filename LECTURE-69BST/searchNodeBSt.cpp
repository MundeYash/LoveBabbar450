
#include<bits/stdc++.h>
using namespace std ; 

class Node{

    public : 
    int data  ; 

    Node* left ; 
    Node* right  ;

    // default constructor 
    Node(int d ){
        this ->data =d ; 
        this->left =NULL ; 
        this ->right = NULL ;
    }

}; 

Node*  insertNodeBST(Node* root , int d ){
    if (root == NULL ){
        //base case 
        root = new Node(d) ;
        return root ;
    }

    if (root->data <d ){
        // right side insertion hoga 
        root ->right = insertNodeBST(root->right , d ) ;
    }
    else{
        root ->left = insertNodeBST(root->left , d) ;
    }
    return root ;
}
void takeInput(Node* &root ){
    int Data  ;
    cin>> Data ; 

    while  (Data!=-1 ){

        root = insertNodeBST(root , Data);
        cin>> Data ;

    }
}
// Function for searching the node in the bst
bool searchNodeBST(Node* root , Node* nodeVal){
    // time :O(log n ) , space : O(n->recursive stack space  )

    // base cases 
    if (root == NULL )return false;
    if (root->data == nodeVal->data )return true ; 

    // recursive case 
    if (root->data< nodeVal->data ){
        // search in right part (greater value )
        return searchNodeBST(root->right, nodeVal) ;
    }
    else{
        // search in the left part (smaller value )
        return searchNodeBST(root->left ,nodeVal);
    }
}



//// Function for searching the node in the bst Iterative approach : Optimised : time : O(log n ) , space ; O(1)

bool searchNodeBST2(Node* root , Node* nodeVal){
    // time :O(log n ) , space : O(1 )

    Node* temp = root ; 

    while (temp ){
        if (temp->data == nodeVal ->data){
            return true ; 
        }
        else if (temp->data <nodeVal->data){
            // key is greater , move to right side 
            temp = temp->right ;
        }
        else{
            temp = temp->left;
        }
    }
    return false;
    
}

int main(){
    Node* root = NULL ; 

    // take input in the bst 
    takeInput(root );// 8 3 10 1 6 14 4 7 13 -1
    Node* n  = new Node(8);

    if (searchNodeBST(root ,n )== true ){
        cout<<"Node exists "<<endl;
    }
    else{
        cout<<"Node does not exists : "<<endl;
    }




  if (searchNodeBST2(root ,n )== true ){
        cout<<"Node exists "<<endl;
    }
    else{
        cout<<"Node does not exists : "<<endl;
    }

    return 0 ;
}

/*
code studio : https://www.codingninjas.com/studio/problems/search-in-bst_1402878 (done )

leetcode : https://leetcode.com/problems/search-in-a-binary-search-tree/ (done)
gfg : https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1 (done)


*/