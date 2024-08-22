#include <bits/stdc++.h>
using namespace std;

// Height of tree : It is the maximum distance from the root to leaf nodes among all the present leaf nodes
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

//Approach 1 : Brute Force Using the level Order traversal : concept => find the maximum level no using level order 

int height1(node* root ){
     //Brute force Approach : O(n) , space : O(n) (iterative approach , level order traversal )
        // concept : find the maximum level number 
        if(!root )return 0 ;
        queue<node* > q ; 
        q.push(root ); 
    int ans =0 , levelNo=1;
        while (!q.empty()){
            int n = q.size(); 

            for (int i= 0;i<n ;i++ ){
                node* frontNode = q.front(); 
                q.pop(); 

                if (frontNode->left){
                    q.push(frontNode->left );
                }

                if (frontNode->right ){
                    q.push(frontNode->right );
                }


            }
            if (levelNo>ans)ans = levelNo;
            levelNo++ ;
        }
        return ans;
}



//************APPROACH -2 : CONCEPT : POSTORDER TRAVERASL (RECURSIVE APPROACH )
// function for finding the height of the binary tree
int heightBinaryTree(node *root)
{
    // concept : maximum of left height , right height + 1;
    // time ; O(n) , space  : O(n)
    if (!root)
        return 0;

    return max(heightBinaryTree(root->left), heightBinaryTree(root->right)) + 1;
}

int main()
{
    node *root;
    buildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1
    inorder(root);

    cout << "\nThe height of the give binary tree is : " << heightBinaryTree(root) << endl;
    return 0;
}

/*
gfg: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
leetcode : https://leetcode.com/problems/maximum-depth-of-binary-tree/ (done)
code studio : https://www.codingninjas.com/studio/problems/height-of-binary-tree_4609628?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf (done)
interviewbit : 
*/