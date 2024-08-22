
#include <bits/stdc++.h>
using namespace std;

// Identical  tree: Given Two tress check whether they are identical or not : Two trees are identical if they have same number of nodes and (all the nodes have same values as well )
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

// function for checking the given two trees are identical or not
bool isIdentical(node *root1, node *root2)
{

    // time : O(n) , space : O(n);
    if (root1 == NULL and root2 == NULL)
        return true;
    // second base case
    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data) and (isIdentical(root1->left, root2->left)) and (isIdentical(root1->right, root2->right));
}

int main()
{

    node *root1;
    buildTree(root1); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1
    node *root2;
    buildTree(root2); // 1 3 7 5  11 17  -1 -1 -1 -1 -1 -1 -1

    if (isIdentical(root1, root2) == true)
    {
        cout << "Identical trees " << endl;
    }
    else
    {
        cout << "Not Identical Trees " << endl;
    }
    return 0;
}
// concept : left check + right right and both trees node value comparison

// time :O(N), space : O(n)
/*

article :  https://takeuforward.org/data-structure/check-if-two-trees-are-identical/
code studio : https://www.codingninjas.com/studio/problems/check-identical-trees_799364?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
interviewbit :
leetcode: https://leetcode.com/problems/same-tree/
gfg : https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1


*/