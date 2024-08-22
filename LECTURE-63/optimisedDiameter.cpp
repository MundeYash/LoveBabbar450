#include <bits/stdc++.h>
using namespace std;

// Diameter of the tree  : The maximum distance between the two nodes
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

// function for helper finding the diameter
pair<int, int> diameter(node *root)
{
    pair<int, int> ans;
    if (!root)
    {
        ans.first = 0;
        ans.second = 0;
        return ans;
    }

    // recursive case
    pair<int, int> leftDia = diameter(root->left);
    pair<int, int> rightDia = diameter(root->right);

    // main checking condition
    int op1 = leftDia.first;
    int op2 = rightDia.first;
    int op3 = leftDia.second + rightDia.second + 1;

    ans.first = max(max(op1, op2), op3);
    ans.second = max(leftDia.second, rightDia.second) + 1;
    return ans;
}
// function for fidning the diameter of the tree
int Optimiseddiameter(node *root)
{
    // time : O(N)  ,space : O(n)
    if (!root)
        return 0;

    return diameter(root).first;
}
int main()
{
    node *root;
    buildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

    cout << "\nThe diameter of given binary tree is : " << Optimiseddiameter(root) << endl;
    return 0;
}
/*
article : https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
code studio : https://www.codingninjas.com/studio/problems/diameter-of-binary-tree_920552?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf (done)
leetcode : https://leetcode.com/problems/diameter-of-binary-tree/ (done)
interviewbit :
gfg : https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1 (done)
*/