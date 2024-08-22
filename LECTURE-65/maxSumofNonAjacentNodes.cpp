
#include <bits/stdc++.h>
using namespace std;

// function creating the class
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

// functino for taking the input for the level build tree
void levelBuildTree(node *&root)
{
    cout << "Enter data :" << endl;
    int data;
    cin >> data;

    // making of queue and their work
    queue<node *> q;

    if (data != -1)
    {
        root = new node(data);
        q.push(root);
    }
    else
    {

        root = NULL;
        return;
    }

    while (!q.empty())
    {

        node *frontNode = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for left child of " << frontNode->data << endl;
        cin >> leftData;

        if (leftData != -1)
        {
            frontNode->left = new node(leftData);
            q.push(frontNode->left);
        }

        int rightData;
        cout << "Enter data for right  child of " << frontNode->data << endl;
        cin >> rightData;

        if (rightData != -1)
        {
            frontNode->right = new node(rightData);
            q.push(frontNode->right);
        }
    }
}

pair<int, int> solve(node *root)
{
    pair<int, int> ans;

    if (!root)
    {
        ans.first = 0;
        ans.second = 0;
        return ans;
    }

    // Recursive case
    pair<int, int> leftCheck = solve(root->left);
    pair<int, int> rightCheck = solve(root->right);

    // include the root node
    ans.first = (root->data + leftCheck.second + rightCheck.second);

    // exclude the root node
    ans.second = max(leftCheck.first, leftCheck.second) + max(rightCheck.first, rightCheck.second);

    return ans;
}

int maxSumNonAdjacent(node *root)
{
    if (!root)
        return 0;
    pair<int, int> ans = solve(root);
}
int main()
{
    node *root;
    levelBuildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

    cout << "The maximum sum of non -adjacent nodes is " << maxSumNonAdjacent(root) << endl;
    return 0;
}

/*
article : https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1 (rem)
gfg  :
code studion :
interview bit :
leetcode :


// homewok try questions 

https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1
https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
https://practice.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

*/