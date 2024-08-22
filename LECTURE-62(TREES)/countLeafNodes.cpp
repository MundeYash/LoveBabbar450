#include <bits/stdc++.h>
using namespace std;
class node
{

public:
    int data;
    node *left;
    node *right;

    // default constructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// function for building  the tree level wise input
void buildTree(node *&root)
{

    queue<node *> q;
    cout << "Enter the data for the root " << endl;

    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *frontNode = q.front();
        q.pop();

        // take the inputs for the left and the right child attach to left and right pointer only if they are not NULL
        cout << "Enter data for left child of  " << frontNode->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            frontNode->left = new node(leftData);
            q.push(frontNode->left);
        }

        // for the right child
        cout << "Enter the data for right child of " << frontNode->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            frontNode->right = new node(rightData);
            q.push(frontNode->right);
        }
    }
}

// // function for the Inorder  traversal
void inorder(node *root , int &count )
{
    if (!root)
        return;

    // format : (LNR)->  left ,node print , right

    inorder(root->left, count );
   // condition for the leaf node 
   if (root->left == NULL and root->right == NULL) count ++ ;
    inorder(root->right , count );
}

// solving using the preorder format 

void preOrder(node* root , int &count ){
    if(!root )return ; 
    if (root->left == NULL and root->right == NULL )count ++ ; 
    preOrder(root->left , count ) ;
    preOrder(root->right , count);



}
int main()
{
    node *root;
    buildTree(root);// 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1 
    int count = 0 ;
    inorder(root, count );
    // preOrder(root , count);
    cout<<"The number of leaf nodes in binary tree is : "<< count <<endl;
    return 0;
}

/*
gfg : https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1 (done

https://practice.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1)  (done )
https://practice.geeksforgeeks.org/problems/size-of-binary-tree/1 (done)

codestudio : https://www.codingninjas.com/studio/problems/count-leaf-nodes_893055?source=youtube&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio (done)
*/