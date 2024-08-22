


#include <bits/stdc++.h>
using namespace std;

// Check Whether the given binary tree is is balanced or not  . Binary tree tree is balanced if the the absolute difference of height of the left subtree and height of the right subtree for every node int the tree is true than it is height balanced other wise not

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
// brute force approach : time : O(n) ,space : O(n)->recursive stack space  ;
// concept : same recursive function is used for finding the height and check condition 
pair<bool , int > isBalanced (node* root ){
    pair<bool , int >   p ; 
    if (!root ){
        p.first = true ; 
        p.second = 0 ; 
        return p ; 
    }

    // recursive case 

    pair<bool,int> leftCheck = isBalanced(root->left) ; 
    pair<bool, int > rightCheck = isBalanced(root->right) ;
    p.second = max(leftCheck.second , rightCheck.second) + 1;

    if (leftCheck.first == true and rightCheck.first == true and abs(leftCheck.second- rightCheck.second)<=1 ){
        p.first = true ; 
    }
    else {
        p.second = false;
    }
    return p ;
}

// function for checking the height balanced condition
bool OptimisedheightBalanced(node *root)
{
     return isBalanced(root).first ;
}

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

int main()
{
    node *root;
    buildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

    cout << "The tree is height balanced " << OptimisedheightBalanced(root) << endl;
    return 0;
}
// time :O(N), space : O(n)
/*

article : 
code studio : https://www.codingninjas.com/studio/problems/is-height-balanced-binary-tree_975497?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf (rem)
interviewbit : https://www.interviewbit.com/problems/balanced-binary-tree/ (done ->o)
leetcode: https://leetcode.com/problems/balanced-binary-tree/ (Done ->o)
gfg : https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1 (done )


*/