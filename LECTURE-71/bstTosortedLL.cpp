#include <bits/stdc++.h>
using namespace std;

// Two Sum Pair in the BST: find a pair of nodes in the binary search tree whose sum is equal to the given target value

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
// function for inserting a node in the binary search tree
Node *insertBST(Node *root, int d)
{
    if (root == NULL)
    {
        // base case
        root = new Node(d);
        return root;
    }

    // checking for position where it is to be inserted
    if (root->data > d)
    {
        // left side node inserted hogi
        root->left = insertBST(root->left, d);
        return root;
    }
    else
    {
        root->right = insertBST(root->right, d);
        return root;
    }
    return root;
}
// function for taking the input in the binary search tree
void takeInput(Node *&root)
{

    int data;
    cout << "Enter the data for BST node input  : " << endl;
    cin >> data;

    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
    return;
}
// for checking correct insertion of nodes print the level order traversal of the input
void levelOrderTraversal(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    // work for the queue
    while (!q.empty())
    {
        int level = q.size();

        for (int i = 0; i < level; i++)
        {
            // take the fornt do work for it

            Node *frontNode = q.front();
            q.pop();

            cout << frontNode->data << " ";

            // work for the child nodes
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

// function for flattening of the binary search  tree

// brute force  : make a link list using store of preorder and create new tree where left point to null and right point to traversal step by step
void inorder(Node *root, vector<int> &ans)
{ // node , left , right
    // base case
    if (!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);

    inorder(root->right, ans);
}
Node *flattenLL1(Node *root)
{
    // Brute force using inorder  store method
    // time : O(n+ n ) , space : O(n+ n + recursive stack space )

    // step 1 : find the in order traversal and store it
    vector<int> ans;
    inorder(root, ans);

    // step 2 : create the list / tree from this inorder traversal
    int n = ans.size();

    Node *dummy = new Node(0);
    Node *temp = dummy;

    for (int i = 0; i < n; i++)
    {

        Node *newNode = new Node(ans[i]);
        temp->right = newNode;
        temp = temp->right;
    }

    return dummy->right;
}

// optimised approach : time : O(n) , sapce : O(1) constant 

void convertToSortedDLL(Node* root , Node* &head ){
    // base case 
    if(root == NULL  )return  ;

    convertToSortedDLL(root->right , head);

    root->right =head ;
    if (head!= NULL ){
        head ->left = root;
    }

    head = root ;

    convertToSortedDLL(root->left , head);


}

Node* flattenLL2 (Node* root ){
    Node* head = NULL ;

    convertToSortedDLL(root , head);

    // step 2 : marking of all the left pointer to the null 
    Node* temp = head ; 
   while (temp ){

       temp->left = NULL ;
       temp = temp->right ;
   }
    return head;
    
}

int main()
{
    Node *root = NULL;
    takeInput(root); // 8 3 10 1 6 14 4 7 13 -1
    levelOrderTraversal(root);
    cout << endl;
    Node *nr = flattenLL1(root);
    levelOrderTraversal(nr);

    cout<<"Second approach : "<<endl;
    Node *nr1  = flattenLL1(root);
    levelOrderTraversal(nr1);

    return 0;
}

/*
article :
codestudiO;https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0  (done )
interviewbit :
leetcode ;
gfg :


*/