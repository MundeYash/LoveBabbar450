// K Sum Path : find all the paths of binary tree where path is sum is equal to k and return the number of those possible paths , tim : O(N) , space : O(h-> height )

#include <bits/stdc++.h>
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

//(Approach -1 ) function for K Sum path  of the given binary tree / Binary search Tree: find the count of number of path sum whose values is equal to the k
void solve(node *root, vector<int> path, int &count, int k)
{
    // base case
    if (!root)
        return;

    // recursive case
    path.push_back(root->data); // adding the current while visiting

    // call for left sub tree
    solve(root->left, path, count, k);

    // call for right sub tree
    solve(root->right, path, count, k);

    // find the sum whose is equal to k
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }

    // before moving back to above remove the previous element
    path.pop_back();
}
int Ksum(node *root, int k)
{
    if (!root)
        return 0;

        // find all the paths and find the sum  and check , return the count 

    vector<int> path;
    int count = 0;
    solve(root, path, count, k);

    return count;
}

int main()
{
    node *root;
    levelBuildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

    cout << "The number of path whose sum is k are  : " << Ksum(root, 45) << endl;

    return 0;
}

/*
article :
gfg  : https://practice.geeksforgeeks.org/problems/k-sum-paths/1 (rem)
code studion : https://www.codingninjas.com/studio/problems/k-sum-path-in-a-binary-tree_893543 (rem)
interview bit :
leetcode : https://leetcode.com/problems/path-sum-iii/ (rem )


*/  
J