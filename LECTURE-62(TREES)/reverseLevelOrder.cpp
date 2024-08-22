// :Reverse the order of level order traversal :Given a binary tree and we need to print the reverse level traversl of the tree means (bottom to up level traversal) and right to left node in tree traverse 


#include <bits/stdc++.h>
using namespace std;

// structure of the tree
class node
{
public:
    int data;
    node *left;
    node *right;

    // default contructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Recursive function for building the tree
node *createTree(node *root)
{ // this function will take the input in preOrder traversal format

    // assume when we get -1 as input the end of the node and tree
    cout << "Enter data :" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    { // means its left and right child does not exits and end of the tree
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    // call for left sub tree
    root->left = createTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = createTree(root->right);

    return root;
}

// function for finding the reverse level order traversal 
vector<int> reverseLevelOrder (node *root ){
// concept : level order traversal + reverse logic 
vector<int>  ans ; 

// step 1 : creation of queue and work 

    queue<node* > q; 
    q.push(root   ); 

    while (!q.empty()){

// step2 : find frontNode and do corresponding related work 
    node* frontNode = q.front() ; 
    q.pop() ;

    ans.push_back(frontNode->data);

//Step3 : Work for the left and the right child 

    if (frontNode->left){
        q.push(frontNode->left);
    }

    if (frontNode->right){
        q.push(frontNode->right);
    }

    }

// Step 4 : reverse the ans 
reverse(ans.begin() , ans.end()) ; 
return ans;





}
void print(vector<int>a ){
    int n = a.size( ) ; 
    for (int i=0 ;i<n ;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    node a(4);
    // dynamically creation of node
    node *b = new node(12);
    cout << a.data << endl;
    cout << b->data << endl;
    node *root = createTree(root);
    // 1 2 -1 -1 3 -1 -1
    // i/p -> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Printing the reverse level    order traversal output : " << endl;
    vector<int> ans = reverseLevelOrder(root);
    print(ans);
 

    return 0;
}
/*
article :
gfg : https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1 (done )
leetcode : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/  (done ->o)
code studio : https://www.codingninjas.com/studio/problems/reverse-level-order-traversal_764339 (done)
interviewbit : https://www.interviewbit.com/problems/reverse-level-order/ (done)



homework : https://practice.geeksforgeeks.org/problems/level-of-a-node-in-binary-tree/1  (done)
https://practice.geeksforgeeks.org/problems/depth-of-node/1 (done)


*/