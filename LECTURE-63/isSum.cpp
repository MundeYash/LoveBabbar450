

#include <bits/stdc++.h>
using namespace std;

// Diameter of the tree  : The maximum distance between the two nodes
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

// *********BRUTE FORCE APPROACH 

int sumFind(node* root ){
    //base 
    if (!root ){
        return 0 ;
    }

    // Leaf Node case 
    if (root->left == NULL and root ->right == NULL ){
        return root ->data ; // sum is root value for the leaf node 
    }

    int leftAns = sumFind(root->left); 
    int rightAns = sumFind(root->right);
    return (leftAns + rightAns + root->data );
}


//          *********OPTIMISED SOLUTION 


//  function for checking the the sum of left subtree and right subtree for all the valid non leaf nodes is equal to their data than -> it is valid sum otherwise not valid sum

pair<bool, int> checkSum(node *root)
{
    pair<bool, int> ans;

    // base case
    if (!root)
    {
        ans.first = true;
        ans.second = 0;
    }

    // second base for the leaf node check
    if (root->left == NULL and root->right == NULL)
    {
        ans.first = true;
        ans.second = root->data;
    }

    // Recursive Case

    pair<bool, int> leftcheck = checkSum(root->left);
    pair<bool, int> rightcheck = checkSum(root->right);
    
    if (leftcheck.first and rightcheck.first and (leftcheck.second + rightcheck.second) == root->data)
    {
        ans.first = true;
       
    }
    else
    {
        ans.first = false;
    }

     ans.second = root->data + leftcheck.second + rightcheck.second;
   
    return ans;
}
bool isSum(node *root)
{
    if (!root)
        return true;

    

        // //Brute 
        // bool leftAns = isSum(root->left) ; 
        // bool rightAns = isSum (root->right ) ; 

        // if (leftAns and rightAns and (sumFind(root->left) + sumFind(root->right ))== root ->data ){
        //     return true  ;
        // }
        // else{
        //     return false;
        // }

        // Optimised 
    return (checkSum(root).first);
}

int main()
{
    node *root;
    buildTree(root); //1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1
    if (isSum(root))
    {
        cout << "Valid Sum / Child Sum property is followed " << endl;
    }
    else
    {
        cout << "Not FOllowed " << endl;
    }
}

//
/*Children Sum Property
article :https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/
leetcode:https://leetcode.com/problems/root-equals-sum-of-children/ (done)
code studio : https://www.codingninjas.com/studio/problems/childrensumproperty_790723 (rem)
interview bit :
gfg : https://practice.geeksforgeeks.org/problems/sum-tree/1 (done )

*/