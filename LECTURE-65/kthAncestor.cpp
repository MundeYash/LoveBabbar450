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


//BRUTE FORCE APPROACH : The Kth ancestor of given binary tree (find the path and kth ancestor )

bool  findAncestors(node* root , int n , vector<int> &path  ){
// time : O(n) , space : O(N)+ O(n)

// base case 
if (!root)return false ;
path.push_back(root->data);

if (findAncestors(root->left , n , path)== true || findAncestors(root->right  , n, path )== true ){
    return true ; 
}

path.pop_back();
return false;
}
int kthAncestor1 (node* root , int targetnode  , int k ){
    // step 1: Genetate the root to node path of given target node and than fetch the kth ancestor 
    vector<int> ans ; 
    if (!root )return -1  ; 

    // other solvable case 
    bool result = findAncestors(root, targetnode , ans  ) ; 
    if (result== false || k >= ans.size() )return -1;


    // remove the targetnode value from the path 
    ans.pop_back() ; 

    return ans[ans.size()-k-1 ];


}


// Optimised Approach for finding the kth ancestor of the binary tree 

node* solvee(node* root , int targetNode , int &k ){
    // base case 
    if (!root )return NULL ; 

    if(k== 0 ){
        return root  ; 
    }

    node* leftCheck = solvee(root->left, targetNode , k ) ; 
    node* rightCheck = solvee(root->right , targetNode , k ) ;
    if (leftCheck !=NULL and rightCheck !=NULL ){
        return root ; // this current node is kth ancestor node 

    }
    else if (leftCheck != NULL and rightCheck == NULL ){
        return leftCheck ;
    }
    else if (leftCheck== NULL and rightCheck != NULL )
    {
        return rightCheck ; 
    }

    return NULL ;
}
int kthAncestor2 (node* root , int targetNode , int k ){
    // time : O(n) , space : O(h->height )
    node* ans = solvee(root, targetNode, k);
    if (ans == NULL ){
        return -1 ;
    }
    return ans->data ;

}

int main()
{
     node *root;
    levelBuildTree(root); // 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

   cout<<"The kth ancestor of given binary tree is "<<kthAncestor1(root, 3 ,1 )<<endl ; 
//    cout<<"The kth ancestor of given binary tree is "<<kthAncestor2(root, 5 ,2 )<<endl ; 

    return 0;
}

// Approach 1 : find the kth ancestor while storing the path from root to nth node return kth ancestor

// Approach 2 : Using Recursion

/*
article :
gfg  :https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1 (rem)
code studion : https://www.codingninjas.com/studio/problems/kth-ancestor-of-a-node-in-binary-tree_842561 (rem)
interview bit :
leetcode :https://leetcode.com/problems/kth-ancestor-of-a-tree-node/  (rem)


*/