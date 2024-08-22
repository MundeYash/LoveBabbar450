#include<bits/stdc++.h>
using namespace std  ; 

class node{
    public : 
    int data ; 
    node* left ; 
    node* right ; 

    // default constructor 
    node(int d ){
        this ->data= d ; 
        this->left = NULL ; 
        this ->right =NULL ; 
    }

};

// function for taking the level wise input of the tree 
void levelBuildTree(node* &root ){
    cout<<"Enter data for root :"<<endl ; 
    int data ; 
    cin>> data  ; 

    if (data ==-1 ){
        root == NULL  ; 
        return ;
    }
    root = new node(data);

    // creation of queue 
    queue<node* > q; 
    q.push(root);

    while (!q.empty()){
        node* f  = q.front() ; 
        q.pop() ; 

        cout<<"Enter the data for left child of "<<f->data <<endl ;
        int leftData ; 
        cin>> leftData; 
        if (leftData!=-1 ){
            f->left = new node(leftData);  
            q.push(f->left);
        }

        cout<<"Enter the data for right child of "<<f->data<<endl ;
        int rightData ; 
        cin>>rightData ;
        if (rightData!=-1 ){
            f->right = new node(rightData);
            q.push(f->right);
        }
        
    }

}

// function for Printing the Bottom  view in the binary tree 
vector<int> bottomView(node* root ){
    // time : O(n ) , space : O(n)
    // concept : Level order traversal + top view 
    // base case 
    vector<int> ans ;
    if (!root )return ans ;

    // recursive case 
    //Step1 : creation of queue and pushing of root node , creation of map 
    map<int , int > topNode ; // map<int hd , int level> node value , one to one mapping 

    queue<pair<node*  , int >> q ;//(queue<pair<node* NODEvalue , int hd >> q )
    q.push(make_pair(root , 0 ));

    // step2 : work for the queue 
    while (!q.empty()){
        pair<node* , int > frontValue  = q.front() ; 
        q.pop() ;

        node* frontNode = frontValue.first;
        int hd = frontValue.second;

        // checking for mapping existence if not ->add it 

        
            // means no value is there at present 
            topNode[hd] = frontNode->data;

  

        // work for the left child 
        if (frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));

        }

        // work for the right child 
        if (frontNode->right){
            q.push(make_pair(frontNode->right , hd + 1) );
        }

    }

    // add the value to the answer from the mapping 

    for (auto i: topNode){
        ans.push_back(i.second);
    }

   

    return ans ;
}

void print(vector<int> a ){
    for (int i=0 ;i<a.size() ;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main (){
    node* root ; 
    levelBuildTree(root);//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
  vector<int> ans =   bottomView(root);
  print(ans)    ;

    

    return 0 ;
}

/*
Article : https://takeuforward.org/data-structure/bottom-view-of-a-binary-tree/
code studio ; https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_893110?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   (done)
leetcode : 
interview bit ; 
gfg : https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1 (done)

*/