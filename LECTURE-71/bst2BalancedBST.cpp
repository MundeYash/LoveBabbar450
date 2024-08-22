#include <bits/stdc++.h>
using namespace std;

// creation of class
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // default constructor called

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// function for input of the level build tree
void levelbuildTree(Node *&root)
{

    queue<Node *> q;

    int data;
    cout << "Enter data for the tree nodes " << endl;
    cin >> data;

    if (data == -1)
    {
        root = NULL;
        return;
    }
    else
    {
        // here data !=- 1 ;
        root = new Node(data);
        q.push(root);
    }

    while (!q.empty())
    {

        Node *frontNode = q.front();
        q.pop();

        // input for left and the right child

        cout << "Enter the data for the left child of " << frontNode->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {

            frontNode->left = new Node(leftData);
            q.push(frontNode->left);
        }

        cout << "Enter the data for the right child of" << frontNode->data << endl;

        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            frontNode->right = new Node(rightData);
            q.push(frontNode->right);
        }
    }

    return;
}

void levelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int level = q.size();

        for (int i = 0; i < level; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            // work for the frontnode
            cout << frontNode->data << " ";

            // work for the left and the right child

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        cout << endl;
    }

    return;
}

// function for changing the given Binary search to Balanced Binary search tree(abosule difference of height of leftsubtree and the right not more than one )
void inorder(Node *root, vector<int> &in)
{
    // base case
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
    return;
}

// create tree from sorted array
Node *array2BST(vector<int> ans, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;

    Node *root = new Node(ans[mid]);
    root->left = array2BST(ans, s, mid - 1);
    root->right = array2BST(ans, mid + 1, e);
    return root;
}
Node *bst2BalancedBST(Node *root)
{
    // convert the given binary tree to the balanced binary search tree by creating new tree

    // step 1 : store the inorder traversal
    vector<int> in;
    inorder(root, in);

    // step  2 : create binary search tree from the sorted array
    int n = in.size();
    return array2BST(in, 0, n - 1);
}

int main()
{
    Node *root = NULL;
    levelbuildTree(root); // 10 8 12 4 -1 -1 16 2 -1 -1 20 -1 -1 -1 -1
    levelOrder(root);

    Node *nr = bst2BalancedBST(root);
    cout << "NEW TREE level order traveral" << endl;
    levelOrder(nr);

    return 0;
}
/*
Article :
code studio : https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0  (done )
leetcode : https://leetcode.com/problems/balance-a-binary-search-tree/   (done)
gfg : https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1 (done)
interview bit : https://www.interviewbit.com/problems/balanced-binary-tree/   (rem )

*/