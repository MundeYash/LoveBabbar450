#include <bits/stdc++.h>
using namespace std;
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


int main()
{
    node *root;
    buildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1
    if (root == NULL)cout << "This is nULL " << endl;
        
    inorder(root);

    return 0;
}