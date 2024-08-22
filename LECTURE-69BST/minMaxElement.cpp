//Find the minimum and maximum element in the binary search tree 
#include<bits/stdc++.h>
using namespace std ; 
class Node{
    public : 
    int data ; 
    Node* left ; 
    Node* right ; 


    // default constructor 
    Node(int d ){
        this ->data = d ; 
        this ->left = NULL ; 
        this ->right = NULL ;
    }

};

Node* insertToBst(Node* root , int d ){
    if (root == NULL ){
        // means first time insertion of node 
        root = new Node(d) ;
        return root ;
    }

    // recursive case 
    if (root->data <d ){
        // right side insertion 
        root ->right = insertToBst(root->right, d ) ; 
        
    }
    else{
        root ->left = insertToBst(root->left , d) ;
    }


    return root ;
}
void takeInput(Node* &root ){
    int data ; 
    cin>> data ; 

    while (data !=-1 ){
        root = insertToBst(root , data ) ; 
        cin>> data ; 
    }
}

// function for finding the minimum element in the bst 
int minElementBST(Node* root ){
    if (!root )return -1 ; // means no minimum element exists 

    // step1 : find the lowest leaf node 

    while (root->left ){
        root = root->left ;
    }
    return root ->data ; 
}


// function for finding the maximum element in the bst 
int maxElementBST(Node* root ){
    if (!root )return -1 ; // means no minimum element exists 

    // step1 : find the lowest leaf node 

    while (root->right ){
        root = root->right ;
    }
    return root ->data ; 
}


int main (){
    Node* root = NULL ; 
    cout<<"Enter the data for the node value of the bst "<<endl;
    takeInput(root);

    cout<<"the maximum element is : "<<maxElementBST(root)<<endl;
    cout<<"the minimum  element is : "<<minElementBST(root)<<endl;
    return  0 ;
}

/*


gfg : 


interview bit ; 

leetcode : 


codestudio : https://www.codingninjas.com/studio/problems/minimum-element-in-bst_8160462?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0 (done)

*/