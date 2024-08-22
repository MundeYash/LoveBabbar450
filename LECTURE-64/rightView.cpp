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

// function for Printing the Right   view in the binary tree (Iterative )
vector<int> rightView(node* root ){
    // time : O(n ) , space : O(n)
    // concept : Level order traversal + top view 
    // base case 
    vector<int> ans ;
    if (!root )return ans ;

    // recursive case 
    queue<node* > q ; 
    q.push(root   );

    while (!q.empty()){
        int level = q.size() ; 
        vector<int> temp ; 

        for (int i=0 ;i<level;i++){
        node* frontNode = q.front() ; 
        q.pop();
        
        temp.push_back(frontNode->data);


        if (frontNode->left){
            q.push(frontNode->left);
        }

        if (frontNode->right){
            q.push(frontNode->right);
        }
        }

        ans.push_back(temp[level-1]);// right most value of each node
       
    }
    

    return ans ;
}


// function for Printing the Right   view in the binary tree (Recursive )

void help(node* root , int level , vector<int > & ans ){
    // base case 
    if (!root )return ; 

    // working condition 
    if (level == ans.size()){
        ans.push_back(root->data);
    }

    // recursive case 
    help(root-> right , level + 1, ans );
    help(root->left, level+ 1, ans );

  

}
vector<int> rightView2(node* root ){
    // time : O(n ) , space : O(n)
    // concept : Level order traversal + top view 
    // base case 
    vector<int> ans ;
    if (!root )return ans ;

    // recursive case 
    help(root, 0, ans)  ;

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
  vector<int> ans =   rightView(root);
  print(ans)    ;
  vector<int> ans1 =   rightView2(root);
  print(ans1)    ;

    

    return 0 ;
}
/*
article : https://takeuforward.org/data-structure/right-left-view-of-binary-tree/
gfg : https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1   (done)
code studio : https://www.codingninjas.com/studio/problems/right-view_764605   (done)
leetcode : https://leetcode.com/problems/binary-tree-right-side-view/submissions/ (done ->b , )
interview bit : https://www.bing.com/ck/a?!&&p=11bca07cabc6ea97JmltdHM9MTY5MjgzNTIwMCZpZ3VpZD0xZDNiZTY4YS1kY2I5LTY5MWItMzcyNy1mN2NhZGRiZjY4OWImaW5zaWQ9NTI1MQ&ptn=3&hsh=3&fclid=1d3be68a-dcb9-691b-3727-f7caddbf689b&psq=right++view+of+binary+tree+practice+leetcode+%2c+interviewbit+%2c+codestudio+%2c+gfg++practice+&u=a1aHR0cHM6Ly93d3cuaW50ZXJ2aWV3Yml0LmNvbS9wcm9ibGVtcy9yaWdodC12aWV3LW9mLWJpbmFyeS10cmVlLw&ntb=1    (Done)

*/