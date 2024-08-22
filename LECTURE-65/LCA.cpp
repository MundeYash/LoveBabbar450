//**very very IMPORTANT
// Sum of longest path from root to leaft nodes , tim : O(N) , space : O(h-> height )

#include<bits/stdc++.h>
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

//(Approach -1 ) function for finding the Lowest Common Ancestor (LCA ) of the given binary tree / Binary search Tree
// function for find all the ancestors of a node

bool findAncestor(node *root, int n, vector<int> &ans)
{
    // take this approach as homework question
    // base case
    if (!root)
    {
        return false;
    }

    //
    if (root->data == n)
    {
        return true;
    }

    bool leftAns = findAncestor(root->left, n, ans);
    bool rightAns = findAncestor(root->right, n, ans);

    if (leftAns || rightAns)
    {
        ans.push_back(root->data);
        return true;
    }
    else
    {
        return false;
    }
}
// Brute Force Approach :
int LCA(node *root, int n1, int n2)
{
    // Step1 : find all the ancestors of node n1 , and node n2 and store in vectors
    vector<int> a1;
    vector<int> a2;

    findAncestor(root, n1, a1);
    findAncestor(root, n2, a2);

    // step 2 : find the first common ancestor from the right side
    int N = a1.size();
    int M = a2.size();
    int i = N - 1, j = M - 1;

    while (i >= 0 and j >= 0)
    {
        int val1 = a1[i];
        int val2 = a2[j];
        if (val1 == val2)
        {
            return a1[i];
        }
        else if (val1 > val2)
        {
            i--;
        }
        else if (val2 > val1)
        {
            j--;
        }
    }

    // step 2 Compare the Ancestors of both the nodes from the back and find the first common ancestor and return the answer
    return -1;
}

// Lowest Common Ancestor Approach -2 (find the common Ancestor of given nodes of the binary tree )

node *lowestCommonAncestor(node *root, int n1, int n2)
{
    // time  : O(n ) , space ; O(h->height )
    // base case
    if (!root)
        return NULL;

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    // recursive case
    node *leftAns = lowestCommonAncestor(root->left, n1, n2);
    node *rightAns = lowestCommonAncestor(root->right, n1, n2);

    if (leftAns != NULL and rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL and rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL and rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    node *root;
    levelBuildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

    int n1 = 7, n2 = 17;
    cout << "The LCA -> Lowest Common Ancestor of given binary tree is : " << lowestCommonAncestor(root, n1, n2)->data << endl;

    return 0;
}
/*
article : https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/
gfg  : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1 (done)
code studion : https://www.codingninjas.com/studio/problems/lca-of-binary-tree_920541?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf(done)
interview bit :
leetcode : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/ (done)








// homework Try question :
https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1

https://practice.geeksforgeeks.org/problems/construct-tree-1/1
https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1


*/