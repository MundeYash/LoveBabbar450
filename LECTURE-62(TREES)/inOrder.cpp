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

// function for the Inorder  traversal
void inorder(node *root)
{
    if (!root)
        return;

    // format : (LNR)->  left ,node print , right

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    cout << "Printing the in-order traversal output : " << endl;
    inorder(root);

    return 0;
}

/*
article :https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree/ ()
code studio : https://www.codingninjas.com/studio/problems/inorder-traversal_3839605?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1 (done ->o)
interviewbit :  https://www.bing.com/ck/a?!&&p=3f58df01449ac708JmltdHM9MTY5Mjc0ODgwMCZpZ3VpZD0xZDNiZTY4YS1kY2I5LTY5MWItMzcyNy1mN2NhZGRiZjY4OWImaW5zaWQ9NTIzMw&ptn=3&hsh=3&fclid=1d3be68a-dcb9-691b-3727-f7caddbf689b&psq=inorder+traversal+practice+gfg++interviewbit+&u=a1aHR0cHM6Ly93d3cuaW50ZXJ2aWV3Yml0LmNvbS9wcm9ibGVtcy9pbm9yZGVyLXRyYXZlcnNhbC8&ntb=1 (done)
leetcode : https://leetcode.com/problems/binary-tree-inorder-traversal/ (done ->o)
gfg : https://practice.geeksforgeeks.org/problems/inorder-traversal/1 (done )



Homework question : https://practice.geeksforgeeks.org/problems/children-sum-parent/1 (rem)

*/