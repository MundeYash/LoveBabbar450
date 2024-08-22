#include <bits/stdc++.h>
using namespace std;
// Lowest common ancestor of two given nodes in the binary search tree 

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
//function for finding the lowest common ancestor of two nodes in the binary search tree 
int LCAbst(Node* root , int val1 , int val2 ){
    // time : O(n) , space : O(h)

    // base case 
    if (!root )return -1 ; 

    // recursive caes 
    if (root->data > val1 and root->data > val2 ){
        // left side 
        return LCAbst(root->left , val1 , val2) ;
    }
    else if (root->data < val1 and root->data < val2 ){
        /// right side 

        return LCAbst(root->right , val1 , val2 ) ; 
    }

    else {
        // for other remaining cases 
        return root->data; 
    }

}
int main (){
    Node* root = NULL ; 
    takeInput(root ) ; 
    levelOrder(root);//15 10 20 8 12 16 25 -1

    cout<<"The lowest common acestor is  "<<LCAbst(root  ,10,20)<<endl;

    
    return 0 ;
}
/*

article : 
codestudio : https://www.codingninjas.com/studio/problems/981280?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website  (done )
interviewbit : 
gfg : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1 (done  )
leetcode : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/ (done )



*/