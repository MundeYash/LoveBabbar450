
#include<bits/stdc++.h>
using namespace std ; 
// finding the kth largest and kth smallest element in the bst 


class node {
    public : 
    int data ; 
    node* left ; 
    node* right ; 


    // default constructor 
    node(int d ){
        this ->data =d ; 
        this ->left = NULL ; 
        this ->right = NULL ;
    }

};

node* insertBST (node* root , int d ){

    // base case 
    if (root == NULL ){
        root = new node(d) ; 
        return root ;
    }

    if (root->data < d ){

        root ->right = insertBST(root->right , d );
        return root ;

    }
    else {
        root ->left = insertBST(root->left , d ) ; 
        return root ;
    }

    return root ;

}
void takeinput (node* &root ){

    int data ; 
    cout<<"Enter data for the binary tree input : "<<endl ;
    cin>> data  ; 

    while  (data !=-1 ){
        root =insertBST (root , data ) ;
        cin>> data ; 
        

    }
    return ;

}



    void inorder(node* root , vector<int> &ans){// format : left call , node store , right call 
        // base case 
        if (!root )return ;

        inorder(root->left , ans ) ; 
        ans.push_back(root ->data);
        inorder(root->right , ans );
    }

    
// function for finding the kth largest element in the bst 

// kth Largest  value == n-k+1 smallest value 
 
int kthLargest1(node* root , int k ){

    // brute force approach: concept : find the inorder traversal , and return n-k value 
    // time : O(n) , space : O(n)
    vector<int> ans ; 
    inorder(root , ans ) ; 
    int n = ans.size() ; 
    return ans[n-k] ;

}

int solveL (node* root , int &counter , int k ){
    // base case

    if (!root )return -1; 

    // left call 
    int rightCheck = solveL(root->right , counter , k ) ;

    if (rightCheck !=-1 ){
        // answer finded 
        return rightCheck ; 
    }

    // node 
    counter++ ; // increment after coming from left 

    if (counter == k )return root  ->data; 

 
    return solveL(root->left , counter , k ) ;


}
int kthLargest2(node* root , int k ){

    // optimised Approach : counter and return 
    // time : O(n) , space : O(n)-> recursive stack space 
    

    // base case 
    if (!root ) return -1 ; 
    int counter =0 ;
    return solveL(root , counter , k );


   



}


// function for finding the kth smallest element in the bst 
int kthSmallest1 (node* root , int k ){

    // brute force approach: concept : find the inorder traversal , and return n-k value 
    // time : O(n) , space : O(n)
     vector<int> ans ; 
    inorder(root , ans ) ; 
    int n = ans.size() ; 
    return ans[k-1] ;


}

int solveS (node* root , int &counter , int k ){
    // base case

    if (!root )return -1; 

    // left call 
    int leftCheck = solveS(root->left , counter , k ) ;

    if (leftCheck !=-1 ){
        // answer finded 
        return leftCheck ; 
    }

    // node 
    counter++ ; // increment after coming from left 

    if (counter == k )return root  ->data; 

  
    return solveS(root->right , counter , k ) ;

}
int kthSmallest2(node* root , int k ){

    
    // base case 
    if (!root ) return -1 ; 

    // concept : counter method and iterater comparison 

    int counter =0 ;
    return solveS(root , counter  , k );

}



int main (){
    node* root = NULL ; 
    takeinput(root ) ;// 8 3 10 1 6 14 4 7 13 -1
    int k=3 ;

    cout<<"The "<<k<<"largest value of the bst is : "<<kthLargest1(root, k)<<endl;
    cout<<"The "<<k<<"largest value of the bst is : "<<kthLargest2(root, k )<<endl;


    // for smallest 

    cout<<"The "<<k<<"  smallest value of the bst is : "<<kthSmallest1(root, k )<<endl;
    cout<<"The "<<k<<"  smallest value of the bst is : "<<kthSmallest2(root, k )<<endl;
    

    return 0 ;
}
/*

//          for smallest 
article : https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree/
codestudio : https://bit.ly/3rf0HrP  (done )
interview bit ; 
leetcode https://leetcode.com/problems/kth-smallest-element-in-a-bst/   (done )
gfg  :https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1?page=1&category[]=Binary%20Search%20Tree&sortBy=submissions (done )



// for largest 
article : https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree/
codestudio : https://bit.ly/31Yjtet   (done )
leetcode  ;
interview bit : 
gfg :  https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1  (done )

*/