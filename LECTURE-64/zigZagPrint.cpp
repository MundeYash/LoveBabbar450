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



vector<int> zigZagLevelOrder(node *root)
{
    
    // // time : o(n) , space : O(n)-> queue using
    vector<int> ans;
    // BAse case

    if (root == NULL)
    {
        return ans;
    }

    // creation of queue and pushing of root node

    queue<node *> q;
    q.push(root);
    // for check , create a flag -> for getting the update of direction
    bool leftToRight = true;

    while (!q.empty())
    {
        int level = q.size();
        vector<int> temp(level);
        for (int i = 0; i < level; i++)
        {
            node *frontNode = q.front();
            q.pop();

            // finding the index of that front node to be stored

            int index = leftToRight ? i : (level - i - 1); // directino
            // store that value at their location
            temp[index] = frontNode->data;

            // pushing the child of frontNode to the queue
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        // direction change karni hogi
        leftToRight = !leftToRight;

        // copying the ans value to the result
        for (auto it : temp)
        {
            ans.push_back(it);
        }
    }
    // return ans;
}


//Optimised Solution 

vector<int> zigZagLevelOrderOptimised(node* root ){
    // time  : O(n) , space : O(1)
    vector<int> ans;
    if(root == NULL) return ans;
    queue<node*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int level = q.size();
        vector<int> temp(level);
        for(int i = 0; i < level; i++){
            node* frontNode = q.front();
            q.pop();
            int index = leftToRight ? i : (level - i - 1); // direction
            temp[index] = frontNode->data;
            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);
            }
            leftToRight = !leftToRight;
            for(auto it : temp) ans.push_back(it);
            }

                

    }
int main()
{
    node *root = NULL; 
    buildTree(root);//1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1 
    
    cout << endl;
    cout<<"HEre"<<endl;
    // vector<int> ans = zigZagLevelOrder(root);
    vector<int> ans = zigZagLevelOrderOptimised(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout<<"HEre"<<endl;
    return 0;
}
/*

Article : https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/
codestudio : https://www.codingninjas.com/studio/problems/zig-zag-traversal_1062662?leftPanelTab=1 (done )
interveiw bit :
leetcode ; https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ (done)
gfg : https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1  (done )
*/