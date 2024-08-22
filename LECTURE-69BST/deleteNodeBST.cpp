#include<bits/stdc++.h>
//*****************IMPORTANT (VVM)         ******************
using namespace std ; 
class Node{
public : 
    int data ; 
    Node* left ; 
    Node* right ;

    // default constructor 

    Node(int d ){
        this ->data= d; 
        this->left  = NULL ; 
        this->right = NULL;
    }
};


// function for inserting node in the bst 
Node*insertToBST(Node* root  , int  d ){
    if (!root ){
        root = new Node(d) ; 
        return root ;
    }

    // recursive case 
    if (root ->data <d ){
        //right side insertion 
        root -> right = insertToBST(root->right , d ) ;

    }
    else{
        root ->left = insertToBST(root->left ,d ) ;
    }

    return root ;
}
void takeInput (Node* &root ){
    int Data ; 
    cin>> Data ; 

    while (Data !=-1 ){
        root = insertToBST(root , Data ) ; 
        cin>> Data;
    }

}


// level order traversal for tree checking
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int level = q.size();
        for (int i = 0; i < level; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            cout << frontNode->data << " ";

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        cout << endl;
    }
}

// function for deleting a particular / node->data value in the binary search tree 
Node* minValue (Node* root ){
    if (!root )return NULL ;

    while (root->left){
        root= root->left ;
    }
    return root ;

}


Node* deleteNodeBST(Node* root , int val ){
    // delete the node whose data is equal to the val 
    // concept : Recursion , time : O(h->height of the binary tree ) , space  : O(n-> recursive stack space )
    

    if (!root )return root  ; 

    // recursive case 
    if (root ->data == val ){

        // important case , 4 options are there for the deletion 

        // 0 child exits 
        if(root->left == NULL and root ->right == NULL ){
            delete root ; 
            return NULL ;
        }

        // 1child exists (either left or right child )

        if (root->left == NULL and root -> right != NULL ){
            // store the right node 
            Node* temp = root->right  ;
            delete root ; 
            return temp ;
        }

        if (root->left != NULL and root->right == NULL ){
            Node* temp = root->left ; 
            delete root ; 
            return temp ;
        }

        // 2child exits (both left and right ){either find maximum from left subtree and replace it with root  or find minimum element form the right and replace it with root , do recursvive call}

        if (root ->left != NULL and root ->right != NULL ) {
            int mini = minValue (root ->right )->data ;// gives minimum value from the right 
            root ->data = mini ; // add min value to the root value 
            root ->right = deleteNodeBST(root->right , mini);
            return root ;

        }

    }

    else if (root ->data <val ){
        // val exists in right subtree (move to the right )
        root ->right = deleteNodeBST(root->right , val) ; 
        return root ;

    }
    else{
        // val exists in the left subtree (move to the left )
        root ->left = deleteNodeBST(root->left , val);
        return root ;
    }

    return root ;
}

int main (){
    Node* root = NULL ; 
    cout<<"Enter the data for the Nodes in the BST :"<<endl ;
    takeInput(root    );//8 3 10 1 6 14 4 7 13 -1
    levelOrder(root);

    cout<<endl;
    root = deleteNodeBST(root,10);
     levelOrder(root);




    return 0 ;
}

/*
article : 
code studio : https://www.codingninjas.com/studio/problems/delete-node-in-bst_920381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf (done )
leetcode : https://leetcode.com/problems/delete-node-in-a-bst/ (done)
interviewbit : 
gfg : 


https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1 (done)

*/