#include <bits/stdc++.h>
using namespace std;
// Inorder Predecessor of a key : the value which lies just before the key in inorder traversal of a binary

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

Node *insertBST(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    // check position for its placement
    if (root->data < d)
    {
        // right side insertion
        root->right = insertBST(root->right, d);
        return root;
    }

    else
    {
        root->left = insertBST(root->left, d);
        return root;
    }
    return root;
}
void takeInput(Node *&root)
{

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
}

// level order traversal for tree checking
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int level = q.size();
        for (int i = 0; i < level; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            cout << frontNode->data << " ";

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
}
int inorderPredecessor1 (Node* root , int key ){
    // brute force approach :, concept : store the inorder tarversal and store and find the value use morris traversal 
}


int inorderPredecessor(Node *root, int key)
{

    // time: O(h ) , space : O(1)
    // iterative approach
    if (!root)
        return -1;

    // other solvable case
    int ans = -1;
    while (root)
    {

        if (root->data >= key)
        {
            // no use this value (left side )
            root = root->left;
        }
        else
        {
            ans = root->data;
            root = root->right;
        }
    }

    return ans;
}
int main()
{
    Node *root = NULL;
    cout << "Enter the data for input of BST node " << endl;
    takeInput(root); // 8 3 10 1 6 14 4 7 13 -1
    // 15 10 20 8 12 16 25 -1
    levelOrder(root);

    cout << "The inorder predecesoor of given bst is : " << inorderPredecessor(root, 10) << endl;

    return 0;
}
/*
article:
gfg :https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1 (done)
code studio : https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_893049?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf (done)
interview bit :


*/