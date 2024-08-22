#include <bits/stdc++.h>
using namespace std;

// structure of the tree
class node
{
public:
    int data;
    node *left;
    node *right;

    // default contructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Recursive function for building the tree
node *createTree(node *root)
{ // this function will take the input in preOrder traversal format

    // assume when we get -1 as input the end of the node and tree
    cout << "Enter data :" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    { // means its left and right child does not exits and end of the tree
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    // call for left sub tree
    root->left = createTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = createTree(root->right);

    return root;
}

// function for the PostOrder traversal
void postOrder(node *root)
{
    if (!root)
        return;

    // format : (LR)N->  left , right ,node print 

    postOrder(root->left);
   
    postOrder(root->right);
     cout << root->data << " ";
}
int main()
{

    node a(4);
    // dynamically creation of node
    node *b = new node(12);
    cout << a.data << endl;
    cout << b->data << endl;
    node *root = createTree(root);
    // 1 2 -1 -1 3 -1 -1
    // i/p -> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Printing the post   order traversal output : " << endl;
    postOrder(root);

    return 0;
}

/*
article : https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree/
code studio : https://www.codingninjas.com/studio/problems/postorder-traversal_3839614?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website (done)
interviewbit : 
leetcode : https://leetcode.com/problems/binary-tree-postorder-traversal/ (done)
gfg : 


*/