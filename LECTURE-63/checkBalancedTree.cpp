
#include <bits/stdc++.h>
using namespace std;

// Check Whether the given binary tree is is balanced or not  . Binary tree tree is balanced if the the absolute difference of height of the left subtree and height of the right subtree for every node int the tree is true than it is height balanced other wise not

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
// brute force approach : time : O(n^2) ,space : O(n)->recursive stack space  ;
// concept : height + checking condition
int height(node *root)
{
    if (!root)
        return 0;

    // recursive case
    return max(height(root->left), height(root->right)) + 1;
}

// function for checking the height balanced condition
bool heightBalanced(node *root)
{
    if (!root)
        return true;
    bool leftCheck = heightBalanced(root->left);
    bool rightCheck = heightBalanced(root->right);
    if (leftCheck and rightCheck and abs(height(root->left) - height(root->right)) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


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

int main()
{
    node *root;
    buildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

    cout << "The tree is height balanced " << heightBalanced(root) << endl;
    return 0;
}

/*
 */

/*

article :
code studio : https://www.codingninjas.com/studio/problems/is-height-balanced-binary-tree_975497?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf (done)
interviewbit : https://www.interviewbit.com/problems/balanced-binary-tree/ (done ->o)
leetcode: https://leetcode.com/problems/balanced-binary-tree/ (Done ->o)
gfg : https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1 (done )


*/