#include<bits/stdc++.h>
using namespace std ; 

// creation of class 
class Node{
    public : 
    int data ; 
    Node* left ; 
    Node* right ; 

    //default constructor called

    Node( int d ){
        this ->data= d ;
        this ->left =NULL ; 
        this ->right = NULL;

    }

};


void levelOrder (Node* root ){
    if (!root )return  ; 
    queue<Node*  > q ; 
    q.push(root ) ;

    while (!q.empty()){
       int level = q.size() ; 

       for (int i=0 ;i<level;i++){
         Node* frontNode = q.front() ; 
        q.pop()  ; 

        // work for the frontnode 
        cout<<frontNode->data <<" ";

        // work for the left and the right child 

        if (frontNode->left ){
            q.push(frontNode->left);
        } 


        if (frontNode->right ){
            q.push(frontNode->right);
        }
       }
       cout<<endl;
    }

    return ;
}


// function for creating the binary search  tree from the sorted array
Node* solve(vector<int >arr , int s , int e ){
    // base case 
    if (s>e )return NULL ; 

    // step 1 : find the mid element and create node 
    int mid = (s+e)/2 ; 
    Node* root = new Node(arr[mid]) ; 

    root ->left = solve(arr , s , mid -1 ) ; 
    root ->right = solve(arr , mid + 1 , e ) ;

    return root ;

} 
Node* sortedArray2BST(vector<int> arr ){
    // concept : find mid and create node , attach smaller values to left and greater  to right 
    // time : O(n ) , space : O(h)
    int n =arr.size() ; 

    return solve(arr , 0 , n-1 ) ; 

    

}


// **********approach 2 : optimised approach 

// function for converting the sorted array to the bt 


// 
int main (){

    //sorted array 
    vector<int>arr ={1,2,3,4,5,6,7};
    Node* root = sortedArray2BST(arr);
    levelOrder(root);
    return 0 ;
}

/*
article : 
code studio : https://www.codingninjas.com/studio/problems/1264995?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website  (rem )
interview bit : https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/  (rem )
leetcode : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/  (done)
gfg : https://practice.geeksforgeeks.org/problems/array-to-bst4443/1  (rem)

https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1  (rem )
interview bit:https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/ (rme ) 

*/