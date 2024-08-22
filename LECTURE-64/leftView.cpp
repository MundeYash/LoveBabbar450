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
vector<int> leftView(node* root ){
    // time : O(n ) , space : O(n)
    // concept : Level order traversal + leftmost element of the each level 
    // base case 
    vector<int> ans ;
    if (!root )return ans ;

    // recursive case 
    queue<node* > q ; 
    q.push(root ) ; 

    while (!q.empty()){
       
        int level = q.size() ; 
        vector<int> temp ; 
        for (int i=0 ;i<level ;i++)
        {

        node* frontNode = q.front() ; 
        q.pop() ;
        temp.push_back(frontNode->data);


        if (frontNode->left){
            q.push(frontNode->left);

        }

        if (frontNode-> right){
            q.push(frontNode->right);
        }

        


        }

        ans.push_back(temp[0]);



    }

    

    return ans ;
}


// function for Printing the Left   view in the binary tree(Recursive approach ) 

void help(node* root , int level , vector<int > & ans ){
    // base case 
    if (!root )return ; 

    // working condition 
    if (level == ans.size()){
        ans.push_back(root->data);
    }

    // recursive case 
    help(root->left, level+ 1, ans );

    help(root-> right , level + 1, ans );

}
vector<int> leftView2(node* root ){
    // time : O(n ) , space : O(n)
    // concept : Recursive approach  
    // base case 
    vector<int> ans ;
    if (!root )return ans ;

    // recursive case 
    help(root, 0, ans);
    

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
  vector<int> ans =   leftView(root);
  vector<int> ans2 = leftView2(root);
  print(ans)    ;
  print(ans2)    ;


    

    return 0 ;
}
/*
article : https://takeuforward.org/data-structure/right-left-view-of-binary-tree/
gfg : https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1 (done->b)
code studio : https://www.codingninjas.com/studio/problems/920519?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website(done)
leetcode : 
interview bit : 

*/