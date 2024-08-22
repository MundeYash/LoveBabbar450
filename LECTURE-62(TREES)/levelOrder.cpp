#include <bits/stdc++.h>
using namespace std;
// Given a binary tree return the level order traversal of it ; 
/*
4 Variation can be created 
    1.simple level order traversal 
    2. Reverse level order traversal 
    3. bottom up level order traversal 
    4. Reverse bottom up level order traversal 
    5.Level Order Traversal in the spiral format (one level : left to right , another level right to left format )
*/
// structure of node of binary tree
class node
{
public:
    int data;
    node *left;
    node *right;

    // whenever the default constructor called
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Recursive function for building the tree
node *createTree(node *root)
{// this function will take the input in preOrder traversal format 

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

// function for printing the level order traversal without use of sepearator 

vector<vector<int>>  levelOrder1(node* root ){
    vector<vector<int>> ans ; 
    if (!root )return ans;
    // step 1 : creation of queue 
    queue<node* > q ; 
    q.push(root   ); 
   
    while (!q.empty()){

       int size = q.size(); 
       vector<int> temp ; 

        for (int i=0 ;i<size ; i++ ){
            node* frontNode = q.front() ; 
            q.pop();
            temp.push_back(frontNode->data); 

            // work for the child nodes 
            
            if(frontNode->left){
                q.push(frontNode->left); 
            }

            if (frontNode->right){
                q.push(frontNode->right);
            }

        }
        ans.push_back(temp );

    }
    

    return  ans; 
}

// // function for printing the level order traversal of the tree using seperater (without using the two loops )
void levelOrder (node* root ){
    // step 1 : creation of queue 
    queue<node* > q ;
    // step 2 : pushing of root node in the queue 
    q.push(root) ; 
    q.push(NULL);// null is here used as the seperator means completion of one level 

    while (!q.empty()){

        // step3 : finding of front node 
        node* front = q.front() ; 
       
        q.pop();// poping of the front node 


        if (front == NULL){
            // means completion of one level of the tree (previous level)
            cout<<endl;
            if (!q.empty()){
                q.push(NULL); // (means current level is now completed here )
            }

        }
        else{

             cout<<front->data<<" ";
            if (front->left){
            q.push(front->left);

        }
        if (front->right){
            q.push(front->right);
        }

        }
        
    }
}

void print(vector<vector<int>>arr )
{
    for (int i= 0 ;i<arr.size() ; i++ ){
        for(int j=0 ;j<arr[i].size() ; j++ ){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
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


    cout<<"Printing the level order traversal output : "<<endl;
    levelOrder(root);
    cout<<"Printing the level order traversal output without using the seperator : "<<endl;
    print(levelOrder1(root));
    return 0;
}
/*
artilce: https://takeuforward.org/data-structure/level-order-traversal-of-a-binary-tree/  
code studio : https://www.codingninjas.com/studio/problems/zigzag-binary-tree-traversal_920532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf (done )
interview bit : https://www.interviewbit.com/problems/level-order/ (done )
leetcode : https://leetcode.com/problems/binary-tree-level-order-traversal/ (done)
gfg : https://practice.geeksforgeeks.org/problems/level-order-traversal/1  (donr)


similiar Question : 
https://www.codingninjas.com/studio/problems/maximum-level-sum_980528?interviewProblemRedirection=true      (rem)

*/