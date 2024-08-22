#include <bits/stdc++.h>
using namespace std;

//Diameter of the tree  : The maximum distance between the two nodes 
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
// height of the tree
int height(node *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

// function for fidning the diameter of the tree
int diameter(node *root)
{
    // time : O(N^2)  ,space : O(n)
    if (!root)
        return 0;

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;
    return max(op1, max(op2,op3));
}
int main()
{
    node *root;
    buildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1
    inorder(root);
    cout << "\nThe diameter of given binary tree is : " << diameter(root) << endl;
    return 0;
}
/*
article : https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
code studio : https://www.codingninjas.com/studio/problems/diameter-of-binary-tree_920552?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf (done)
leetcode : https://leetcode.com/problems/diameter-of-binary-tree/ (done)
interviewbit : 
gfg : https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1 (done)
*/