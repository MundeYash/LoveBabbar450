// Important Question :DIAGONAL TRAVERSAL OF A BINARY TREE 
#include<bits/stdc++.h>
using namespace std; 
class Node{

    public :
        int data ; 
        Node* left ; 
        Node* right ; 


        // default constructor 
        Node(int d ){
            this ->data =d ; 
            this ->left = NULL ; 
            this->right = NULL ;
        } 
        
};

// function for creating the binary tree level wise 
void levelBuildTree(Node* &root ){
    int data ; 
    cout<<"Enter data ";
    cin>> data ; 
    if (data ==-1 ){
        root = NULL ; 
        return ;
    }

    Node* temp = new Node(data ); 
    queue<Node*> q; 
    q.push(temp); 

    while (!q.empty()){
        Node* frontNode = q.front() ; 
        q.pop(); 
        
        cout<<"Enter the data for left child of "<<frontNode->data <<endl;
        int leftData ; 
        cin>> leftData ; 
        if (leftData!=-1 ){
            frontNode->left = new Node(leftData);
            q.push(frontNode->left);
        }

    
        cout<<"Enter the data for right  child of "<<frontNode->data <<endl;
        int rightData  ; 
        cin>> rightData ; 
        if(rightData !=-1 ){
            frontNode->right = new Node(rightData);
            q.push(frontNode->right);
        }
    }

    root = temp ; 
    return ;

}


// function for finding the Diagonal Traversal of a binary tree 
vector<int> diagonalTraversal (Node* root ){
    vector<int> ans ; 
    if (!root )return ans ; 

    queue<Node*> q; 
    q.push(root); 

    while (!q.empty()){
        Node* frontNode =q.front(); 
        q.pop();

        while (frontNode != NULL ){
            ans.push_back(frontNode->data );
            if (frontNode->left ){
                q.push(frontNode->left );
            }

            frontNode= frontNode->right;
        }
    }

    return ans;
}

void print(vector<int> arr ){
    int n = arr.size(); 
    for (int i=0 ;i<n ;i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main ()
{
    Node* root = NULL ; 

    levelBuildTree(root);//1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1
    vector<int> ans = diagonalTraversal(root);
    print(ans);
    return  0 ;
}


/*

gfg : https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1   (done)
code studio : https://www.codingninjas.com/studio/problems/diagonal-traversal_893029   (done)
leetcode : 
interview bit : 
https://www.interviewbit.com/problems/diagonal-traversal/           (done)





https://www.codingninjas.com/studio/problems/diagonal-anagram_794951?interviewProblemRedirection=true        (done)
https://www.codingninjas.com/studio/problems/diagonal-traversal_920391?interviewProblemRedirection=true      (done)
*/