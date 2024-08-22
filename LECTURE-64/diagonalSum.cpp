
// DIAGONAL SUM  : Given a binary tree and we need to find the diagonal wise sum of nodes
#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->right = NULL;
    }
};

void levelBuildTree(Node *&root)
{
    // int data;
    // cout << "Enter data ";
    // cin >> data;

    // if (data == -1)
    // {
    //     root = NULL;
    //     return;
    // }

    // queue<Node *> q;
    // Node *temp = new Node(data);
    // q.push(temp);

    // while (!q.empty())
    // {
    //     Node *frontNode = q.front();
    //     q.pop();

    //     int leftData;
    //     cout << "Enter data for adding value in left of " << frontNode->data << endl;
    //     cin >> leftData;

    //     if (leftData != -1)
    //     {
    //         frontNode->left = new Node(leftData);
    //         q.push(frontNode->left);
    //     }

    //     int rightData;
    //     cout << "Enter the data for adding the values in right of " << frontNode->data << endl;
    //     cin >> rightData;

    //     if (rightData != -1)
    //     {
    //         frontNode->right = new Node(rightData);
    //         q.push(frontNode->right);
    //     }
    // }

    // root = temp;
    // return;

     int data ; 
    cout<<"Enter data :"<<endl ; 
    cin>> data ; 
   
   if (data !=-1 ){
     root = new Node(data);

   }
   else {
    root = NULL ; 
    return ;
   }
    queue<Node* >  q ; 
    q.push(root   );

    while (!q.empty()){
        Node* f  = q.front() ; 
        q.pop() ; 



        cout<<"Enter data for left child of :"<<f->data <<endl ; 
        int left ; 
        cin>> left ; 
        
        if (left!=-1 ){
            f->left = new Node(left);
            q.push(f->left);
        }


        cout<<"Enter data for right  child of :"<<f->data <<endl ; 
        int right  ; 
        cin>> right ;

        if(right !=-1 ){
            f->right = new Node(right);
        
            q.push(f->right);
        } 
    

    }
}
// concept : Mapping of number for each diagonal and queue for traversing for each level

vector<int> diagonalSum(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    map<int, vector<int>> nodes;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> frontValue = q.front();
        q.pop();

        Node *frontNode = frontValue.first;
        int index = frontValue.second;

        // work
        nodes[index].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, index + 1)); // for moving left increament the index
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, index)); // for moving right no need to change the index
        }
    }

    // iterating over the map to find sum of all nodes diagonally wise
    for (auto i : nodes)
    {
        int sum = 0;
        for (auto j : i.second)
        {
            sum += (j);
        }
        ans.push_back(sum);
    }

    return ans;
}

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
    Node *root = NULL;

    levelBuildTree(root); // 1 3 5 7 11 17 17 -1 -1 -1 -1 -1 -1 -1
    vector<int> ans = diagonalSum(root);
    print(ans);

    return 0;
}
/*
Similiar Question :
https://www.codingninjas.com/studio/problems/diagonal-anagram_794951?interviewProblemRedirection=true        (rem)
*/