


#include<bits/stdc++.h>
using namespace std ; 


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
// aprroach 1 : Find inorder traversal and sorting check 


    void inorder(node* root , vector<int> &ans){// format : left call , node store , right call 
        // base case 
        if (!root )return ;

        inorder(root->left , ans ) ; 
        ans.push_back(root ->data);
        inorder(root->right , ans );
    }
bool validBST1 (node* root ){
    // concept : inorder Traversal store + sorted check or not  , time : O(n) , space : O(n)
    vector<int> ans ; 

    // step 1 : store the inorder traversal 
    inorder(root , ans ) ;

    // step 2 : check for stored traversal or not 
    int n = ans.size() ; 

    for (int i=0 ;i<n-1 ;i++){
        if (ans[i]>= ans[i+1])return false;
    }

    // after checking for whole traversal still not find any violation 
    return true ;
}



// approach 2 : concept : range and recursion 
bool check(node* root , int minValue , int maxValue ){
    // base case 
    if (!root )return true ; 
   
    if (root->data >= minValue and root->data <= maxValue ){

    bool leftCheck = check(root ->left , minValue , root->data);// range is minvalue to root ka data (left subtree )
    bool rightCheck = check(root ->right  ,  root->data , maxValue);// range is   root ka data to maxvalue (right  subtree )
    return leftCheck && rightCheck ;

    }
    else {
        return false;
    }

}
bool validBST2(node* root ){
    // optimised approach : // concept :range of value in left and right subtree for all nodes , time : O(n ) , space : O(n) recursive stack space 

    if (!root )return true ; 
    return check(root , INT_MIN , INT_MAX ) ;

}

int main (){
    node* root = NULL ; 
    takeinput(root ) ;// 8 3 10 1 6 14 4 7 13 -1

    cout<<"The given binary tree is binaray search tree "<<validBST1(root )<<endl  ; 
    cout<<"The given binary tree is binaray search tree "<<validBST2(root )<<endl  ; 
    return 0 ;
}
/*
Validate BST : check whether the given binary tree is a BST or not 
article : 
code studio : https://www.codingninjas.com/studio/problems/check-bst_5975?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf (rem )

https://www.codingninjas.com/studio/problems/validate-bst_981275?leftPanelTab=0  (done )
leetcode : https://leetcode.com/problems/validate-binary-search-tree/  (done)

gfg : https://practice.geeksforgeeks.org/problems/check-for-bst/1  (done  )

interview bit : 
*/