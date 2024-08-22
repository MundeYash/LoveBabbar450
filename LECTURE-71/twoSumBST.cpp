#include <bits/stdc++.h>
using namespace std;

// Two Sum Pair in the BST: find a pair of nodes in the binary search tree whose sum is equal to the given target value

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // default constructor

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// function for inserting a node in the binary search tree
Node *insertBST(Node *root, int d)
{
    if (root == NULL)
    {
        // base case
        root = new Node(d);
        return root;
    }

    // checking for position where it is to be inserted
    if (root->data > d)
    {
        // left side node inserted hogi
        root->left = insertBST(root->left, d);
        return root;
    }
    else
    {
        root->right = insertBST(root->right, d);
        return root;
    }
    return root;
}
// function for taking the input in the binary search tree
void takeInput(Node *&root)
{

    int data;
    cout << "Enter the data for BST node input  : " << endl;
    cin >> data;

    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
    return;
}
// for checking correct insertion of nodes print the level order traversal of the input
void levelOrderTraversal(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    // work for the queue
    while (!q.empty())
    {
        // take the fornt do work for it

        Node *frontNode = q.front();
        q.pop();

        cout << frontNode->data << " ";

        // work for the child nodes
        if (frontNode->left)
        {
            q.push(frontNode->left);
        }

        if (frontNode->right)
        {
            q.push(frontNode->right);
        }
    }

    return;
}

//*********Function for checking whether the target pair exits in the bst
void inorder(Node *root, vector<int> &ans)
{
    // base case
    if (!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

bool TwoSumBST(Node *root, int target)
{

    // concept : Inorder Store + check for pair sum (two pointer method)

    // step 1 : find the inorder Traversal
    vector<int> ans;
    inorder(root, ans);

    // step 2 : Check for the valid pair using the two pointer approach

    int n = ans.size();

    // 2 pointers taken
    int start = 0, end = n - 1;
    while (start < end)
    {
        int value = ans[start] + ans[end];

        if (value == target)
            return true;
        else if (value > target)
        {
            // decrease the sum (move to left side )
            end--;
        }
        else
        {
            // increase the sum (move to the right side )
            start++;
        }
    }
    return false;
}
int main()
{
    Node *root = NULL;
    takeInput(root);
    levelOrderTraversal(root);

    // for printing the level order traversal
    int target = 10;

    if (TwoSumBST(root, target))
    {
        cout << "\nThe valid pair exists : " << endl;
    }
    else
    {
        cout << "\nThe valid pair does not exists " << endl;
    }

    return 0;
}
/*
article :
code studoi ; https://www.codingninjas.com/studio/problems/pair-sum-in-bst._920493?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   (done)
leetcode : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/ (done)
gfg: https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1  (done)
interveiw bit ; https://www.interviewbit.com/problems/2sum-binary-tree/  (rem )


hacker rank :
*/