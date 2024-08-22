

#include<bits/stdc++.h>
using namespace std ; 

// creation of class 
class node{
    public : 
    int data ; 
    node* left ; 
    node* right ; 

    //default constructor called

    node( int d ){
        this ->data= d ;
        this ->left =NULL ; 
        this ->right = NULL;

    }

};
// function for input of the level build tree 
void levelbuildTree(node* & root ){

    queue<node*  > q ; 
    
    int data ; 
    cout<<"Enter data for the tree nodes "<<endl;
    cin>> data ; 

    if (data == -1 ){
        root = NULL ; 
        return ;
    }
    else{
        // here data !=- 1 ;
        root = new node(data);
        q.push(root);
    }


    while (!q.empty()){

        node* frontNode = q.front() ; 
        q.pop() ; 

        // input for left and the right child 

        cout<<"Enter the data for the left child of "<<frontNode->data <<endl ;
        int leftData ; 
        cin>> leftData ; 
        if (leftData !=-1 ){

            frontNode->left = new node(leftData);
            q.push(frontNode->left);

        }

        cout<<"Enter the data for the right child of"<<frontNode->data<<endl ;

        int rightData ; 
        cin>> rightData ; 

        if (rightData!=-1 ){
            frontNode->right = new node(rightData);
            q.push(frontNode->right);  
        }


    }

    return ;


}

void levelOrder (node* root ){
    if (!root )return  ; 
    queue<node*  > q ; 
    q.push(root ) ;

    while (!q.empty()){
       int level = q.size() ; 

       for (int i=0 ;i<level;i++){
         node* frontNode = q.front() ; 
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

// function for flattening of the binary tree 



// brute force  : make a link list using store of preorder and create new tree where left point to null and right point to traversal step by step 
    void preorder(node* root , vector<int> &ans ){// node , left , right 
        // base case 
        if (!root )return ;
        ans.push_back(root->data); 
        preorder(root->left, ans ) ; 
        preorder(root->right , ans ) ;

    }
node*  flattenLL1 (node* root ){
    // Brute force using preorder store method 
    // time : O(n+ n ) , space : O(n+ n + recursive stack space )

    // step 1 : find the pre order traversal and store it 
    vector<int> ans ; 
    preorder(root ,ans );


    // step 2 : create the list / tree from this preorder traversal 
    int n = ans.size() ; 

    node* dummy = new node(0);
    node* temp = dummy  ; 

    for (int i=0 ;i<n ;i++){

        node* newNode = new node(ans[i]);
        temp ->right = newNode ; 
        temp = temp ->right ;

    }

    return dummy->right ;





}

// optimised approach : time :O(N) and space : O(1) , using morris traveresal 


void flattenLL3(node* root ){
    // we need to make the changes to the root node itself
    // concept : Morris traversal , time : O(n) , space : O(1)

    node* pre , *curr ; 
    curr = root ; 

    while (curr){

        if (curr ->left != NULL ){
            // pred exists 
            pre = curr->left ;

            while (pre->right != NULL ){
                pre = pre ->right;
            }


            pre ->right = curr ->right ; 
            curr ->right = curr ->left ; 

            curr ->left = NULL ;


        }
        curr  = curr ->right ;
    }




}
int main (){
    node* root = NULL  ; 
    levelbuildTree(root  );//1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1
    levelOrder(root   ) ; 
    // node* root1 = flattenLL1(root );

    // node* root2 = flattendLL2 (root );
    flattenLL3(root);
    levelOrder(root  );

    return 0 ;
}
/*InPlace changes karne  h 

code studio : https://www.codingninjas.com/studio/problems/flatten-binary-tree-to-linked-list_1112615 (done)
leetcode : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/ (done)

gfg : https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/ (done )
InterviewBit : https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/  (rem )
*/