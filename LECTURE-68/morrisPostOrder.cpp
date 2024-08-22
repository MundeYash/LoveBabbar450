#include <bits/stdc++.h>
using namespace std;
// Morris PostOrder traversal for the binary tree : In this traversal we will be traversing all the nodes with 3 times with the O(n)time and constant O(1)space

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

// function for creating the tree
void leveLbuildTree(node *&root)
{
    int data;
    cin >> data;
    if (data == -1)
    {
        root = NULL;
        return;
    }
    else
    {
        root = new node(data);
    }

    queue<node *> q;
    q.push(root);

    // work for the queue

    while (!q.empty())
    {
        node *frontNode = q.front();
        q.pop();

        cout << "Enter the data for the left child of " << frontNode->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            frontNode->left = new node(leftData);
            q.push(frontNode->left);
        }

        cout << "Enter the data for the right  child of " << frontNode->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            frontNode->right = new node(rightData);
            q.push(frontNode->right);
        }
    }

    return;
}

// Function for printing / storing  the post order traversal using the morris traversal
void postMorris(node *root, vector<int> &ans)
{
    // follow the same concept of the morris traversal but instead of traversing in the right part , traverse in the left part

    // step 1: creation of two pointers and intializing one of them with the root

    node *curr, *pre;

    curr = root;

    while (curr)
    {
        if (curr->right == NULL)
        {

            // store the ans and move
            ans.push_back(curr->data);

            curr = curr->left;
        }
        else
        {
            // means predecessor value exists
            pre = curr->right;

            while (pre->left != NULL and pre->left != curr)
            {
                pre = pre->left;
            }

            if (pre->left == NULL)
            {

                // store the ans and move
                ans.push_back(curr->data);
                pre->left = curr;
                curr = curr->right;
            }
            else
            {
                // or (pre  ->rigth == curr )
                pre->left = NULL;
                curr = curr->left;
            }
        }
    }

    return;
}
vector<int> postOrderMorris(node *root)
{

    vector<int> ans;
    if (!root)
        return ans;

    postMorris(root, ans);

    // step 2 : we have got the reverse post order of the given tree using morris traversal 
    reverse(ans.begin() ,ans.end() );

    return ans;
}

// function for printing the vector
void print(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    node *root;
    leveLbuildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1
    vector<int> ans = postOrderMorris(root);
    cout << "The post order traversal is  :" << endl;
    print(ans);

    return 0;
}
/*
Morris Post order 
gfg: 
leetcode : 
code studio : 
interview bit ;

*/