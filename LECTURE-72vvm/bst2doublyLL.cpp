
#include <bits/stdc++.h>
using namespace std;

// convert the given binary search tree to the doubly link list 


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

    
    return head;
    
}
// for printing the doubly link list 

void printDLL(Node* head ){
    while (head){

        cout<<head ->data ;
        head = head ->right ; 
    }
}
int main()
{
    Node *root = NULL;
    takeInput(root); // 8 3 10 1 6 14 4 7 13 -1
    levelOrderTraversal(root);
    cout << endl;
   
   Node* nh = flattenLL2(root);

//    cout<<endl;
//    levelOrderTraversal(nh) ; 


cout<<"This is printing :"<<endl;
   printDLL(nh);

    return 0;
}



/*

code studio : 
https://www.codingninjas.com/studio/problems/sorted-linked-list-to-balanced-bst_842564?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0 (rem)

gfg : https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1  (done )

leetcode : 
interviewbit : 

*/