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

// function for creating the binary search  tree from the given preorder traversal

Node *insertNodeBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    else if (root->data < d)
    {
        // right side
        root->right = insertNodeBST(root->right, d);
        return root;
    }
    else
    {
        root->left = insertNodeBST(root->left, d);
        return root;
    }
    return root;
}
Node *preorder2BSTApproach1(vector<int> arr)
{
    Node *root = NULL;
    int n = arr.size();

    // use the concept of adding nodes in bst
    // time : O(n^2 ) , space : O(1)
    for (int i = 0; i < n; i++)
    {
        root = insertNodeBST(root, arr[i]);
    }

    return root;
}

// approach 2 ::::::::::::
int search(vector<int> in, int element)
{
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}
Node *solve2(vector<int> pre, vector<int> in, int n, int &index, int inorderStart, int inorderEnd)
{
    if (inorderStart > inorderEnd || index >= n)
        return NULL;

    int element = pre[index++];

    Node *root = new Node(element);
    int position = search(in, element);
    root->left = solve2(pre, in, n, index, inorderStart, position - 1);
    root->right = solve2(pre, in, n, index, position + 1, inorderEnd);

    return root;
}
Node *preorder2BSTApproach2(vector<int> pre)
{

    // create tree from the inorder(get by sorting the preorder ) and pre order

    // time : O(n logn )  , space : O(1);

    // step 1 : find the inorder traversal by sorting preorder
    vector<int> in = pre;
    sort(in.begin(), in.end());

    // step 2 : appy the concept of construct tree form inorder and pre order
    int preorderIndex = 0;
    int n = in.size();
    int inorderStart = 0, inorderEnd = n - 1;
    int index = 0;

    Node *root = solve2(pre, in, n, index, inorderStart, inorderEnd);
    return root;
}

// optimised approach

Node* solve3(vector<int>&pre , int mini , int maxi , int &index ){
    // base case 
    if (index>=pre.size())return NULL ; 

    // second base 
    if (pre[index ]<mini || pre[index ]> maxi )return NULL ;
    // step 1 : create a node corresponding to pre element at index 
    Node* root= new Node(pre[index ++ ] );
    root->left = solve3(pre , mini , root->data , index) ; 
    root ->right = solve3(pre , root->data , maxi , index) ; 
    return root ;
}
Node *preorder2BSTApproach3(vector<int> pre)
{

    // optimised approach : time : O(n)

    // concept : range based solving
    int n = pre.size() ; 
    int index =0; 
    Node* root = solve3(pre  ,INT_MIN , INT_MAX , index  ) ;

    return root ;

}

//
int main()
{
    vector<int> pre = {10, 5, 1, 7, 40, 50};
    // Node *root1 = preorder2BSTApproach1(pre);
    // // Node* root2 = preorder2BSTApproach2(pre);
    Node* root3 = preorder2BSTApproach3(pre);
    levelOrder(root3);

    return 0;
}

/*
leetcode  : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/  (done)
code studio : https://www.codingninjas.com/studio/problems/construct-bst-from-preorder-traversal_2689307?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf  (done)

gfg : https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1 (rem )

interview bit :   https://www.interviewbit.com/problems/construct-bst-from-preorder/     (rem )
https://www.interviewbit.com/problems/valid-bst-from-preorder/  (rem )
*/