#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // defalut constructor

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
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

// function for printing the preorder traversal
void preorder(Node *root)
{
    // node print ,  left,  right
    if (!root)
        return;
    cout << root->data << " ";

    // call for left subtree
    preorder(root->left);

    // call for right subtree
    preorder(root->right);
}

// function for printing the inorder traversal
void inorder(Node *root)
{
    // node print ,  left,  right
    if (!root)
        return;

    // call for left subtree
    inorder(root->left);

    cout << root->data << " ";

    // call for right subtree
    inorder(root->right);
}

// function for printing the postorder traversal
void postorder(Node *root)
{
    // node print ,  left,  right
    if (!root)
        return;

    // call for left subtree
    postorder(root->left);

    // call for right subtree
    postorder(root->right);

    cout << root->data << " ";
}
// function for creating a binary search search from a stream of the given input
Node *insertToBST(Node *root, int Data)
{
    // time complexity : O(log n ) : how check youself 

    // base case

    if (root == NULL)
    {
        // this is first node is created
        root = new Node(Data);
        return root;
    }

    // Recursive case (means some nodes are already present )
    if (root->data < Data)
    {
        // right side insertion
        root->right = insertToBST(root->right, Data);
    }
    else
    {
        root->left = insertToBST(root->left, Data);
    }

    return root; // final root node of the created bst
}

// function for taking the input stream
void takeInput(Node *&root)
{
    int Data;
    cin >> Data;

    while (Data != -1)
    {

        root = insertToBST(root, Data);
        cin >> Data;
    }

    // as you get the input -1 mean no further in bst exists
    return;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the data for BST :" << endl;
    takeInput(root); // 8 3 10 1 6 14 4 7 13 -1

    cout << "Printing the BST : " << endl;
    cout << "\nPrinting the level order traversal :" << endl;
    levelOrder(root);

    cout << "\nPrinting the preorder traversal :" << endl;
    preorder(root);

    cout << "\nPrinting the inorder traversal " << endl;
    inorder(root);

    cout << "\nPrinting the postorder traversal " << endl;
    postorder(root);

    return 0;
}

/*
insertion of node in bst : 
codestudoi ; 
leetcode ; https://leetcode.com/problems/insert-into-a-binary-search-tree/description/ (done )
interviewbit ; 
gfg : https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1 (rem )
*/