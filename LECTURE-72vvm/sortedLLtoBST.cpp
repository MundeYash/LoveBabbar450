#include<bits/stdc++.h>
 using namespace std ; 
// convert the given sorted link list to the balanced binary search tree 

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

// insertion doubly link list nodes 

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

 int main (){
    return 0 ;
 }

/*

article : 
codestudio : https://www.codingninjas.com/studio/problems/sorted-linked-list-to-balanced-bst_842564?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0  (rem )
https://www.codingninjas.com/studio/problems/list-to-tree_2676010?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0  (rem)
leetcode : 
gfg : https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1  (rem)
interview bit : 

*/