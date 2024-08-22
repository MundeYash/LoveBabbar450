#include <bits/stdc++.h>
using namespace std;
// Question : Is given binary tree is heap : We have given a binary tree and we need to check whether the given binary tree is heap or not (may be max heap or min heap )
// given an binary and we need find whether the given binary tree is heap (complete binary tree + max order property follows )
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // default constuctor
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// function for building  the tree level wise input
void buildTree(Node *&root)
{

    queue<Node *> q;
    cout << "Enter the data for the root " << endl;

    int data;
    cin >> data;

    if (data != -1)
    {
        root = new Node(data);
        q.push(root);
    }
    else
    {
        root = NULL;
        return;
    }

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        // take the inputs for the left and the right child attach to left and right pointer only if they are not NULL
        cout << "Enter data for left child of  " << frontNode->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            frontNode->left = new Node(leftData);
            q.push(frontNode->left);
        }

        // for the right child
        cout << "Enter the data for right child of " << frontNode->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            frontNode->right = new Node(rightData);
            q.push(frontNode->right);
        }
    }
}

void preorder(Node *root)
{
    // base
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}

int countNodes(Node *root)
{
    if (!root)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isCBT(Node *root, int index, int cnt)
{

    // base case
    if (!root)
        return true;

    if (index >= cnt)
    {
        return false;
    }
    bool leftCheck = isCBT(root->left, (2 * index + 1), cnt);
    bool rightCheck = isCBT(root, (2 * index + 2), cnt);
    return leftCheck && rightCheck;
}

bool isMaxorder(Node *root)
{

    // base case
    if (!root)

        // case 1 : 0 child
        if (root->left == NULL and root->right == NULL)
        {
            // leaf node is always a heap
            return true;
        }

    // case 2 : 1 child
    if (root->left != NULL and root->right == NULL)
    {
        // left nodes exists but not right
        return (root->data > root->left->data);
    }
    if (root->left == NULL and root->right != NULL)
    {

        // right node exists but not left
        return (root->data > root->right->data);
    }

    // case 3 : both 2childs exists
    else
    {
        bool leftCheck = isMaxorder(root->left);
        bool rightCheck = isMaxorder(root->right);
        return (leftCheck && rightCheck && (root->data > root->left->data and root->data > root->right->data));
    }
}
// Important functiion  : function for checking whether the given binary tree is max heap or not
bool isBT_Heap(Node *root)
{
    // time : O(n) , space : O(H)

    // step 1: check if the given binary tree is complete binary tree or not
    int index = 0; /// because starting index of root node is 0 (0 based index ing );
    int cnt = countNodes(root);// O(n)
    bool check1 = isCBT(root, index, cnt);//O(n)
    bool check2 = isMaxorder(root); // o(n)

    if (check1 && check2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// function _for array to bt converstion

int main()
{

    vector<int> arr1 = {1, 23, 3, 13, 11, 35, 10};
    int n1 = arr1.size();

    Node *root;
    buildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1
    preorder(root);
    // if (root == NULL)
    //     cout << "This is nULL " << endl;

    if (isBT_Heap(root))
    {
        cout << "This is callled " << endl;
        cout << "This is heap" << endl;
    }
    else
    {

        cout << "This is not a heap " << endl;
    }

    cout << "ended" << endl;

    return 0;
}
/*
code studio ; https://www.codingninjas.com/studio/problems/is-binary-heap-tree_893136?leftPanelTab=0&count=25&page=1&search=is%20bina&sort_entity=order&sort_order=ASC (done)
leet code  ;
gfg  : https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1 (done)
interview :
*/
