#include <bits/stdc++.h>
using namespace std;
// structure of node of binary tree
class node
{
public:
    int data;
    node *left;
    node *right;

    // whenever the default constructor called
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Recursive function for building the tree
node *createTree(node *root)
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    // this function will take the input in( preOrder traversal format )

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

int main()
{
    node a(4);
    // dynamically creation of node
    node *b = new node(12);
    cout << a.data << endl;
    cout << b->data << endl;
    node *root = createTree(root);
    cout<<"Code working fine ";
    return 0;
}
/*
*/