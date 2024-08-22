// Sum of longest path from root to leaft nodes , tim : O(N) , space : O(h-> height )

#include<iostream> 
#include<queue>
using namespace std  ; 

// function creating the class 
class node {
    public : 
    int data ; 
    node* left ; 
    node* right ; 

    // default constructor 
    node(int d ){
        this->data =d ; 
        this->left = NULL  ; 
        this ->right = NULL ;

    }

};

// function for taking the input for the level build tree 
void levelBuildTree(node* &root ){
    cout<<"Enter data :"<<endl ; 
    int data  ; 
    cin>> data ; 

    
    // making of queue and their work 
    queue<node* > q ; 



   if (data !=-1 ){
    root = new node(data);
     q.push(root) ; 

   }
   else{

    root = NULL ; 
     return ;
   }

    

    while(!q.empty()){

        node* frontNode = q.front() ; 
        q.pop() ; 

         int leftData ; 
            cout<<"Enter data for left child of "<<frontNode->data <<endl ;
            cin>>leftData ; 

       
           

            if (leftData!=-1 ){
                frontNode->left  = new node(leftData);
                q.push(frontNode->left);
            }

        

            int rightData ; 
            cout<<"Enter data for right  child of "<<frontNode->data <<endl ;
            cin>>rightData ; 
     
           
            if (rightData!= -1 ){
                frontNode->right = new node(rightData);
                q.push(frontNode->right);    
            }
            
        
    }


}

//(Approach -1 ) function for find the root to leaf longest sum path and value 
pair<int , int > find (node* root ){
    // concept  Used : height -> 
    
    // time Complexity : o(n) , space : O(h)
    pair<int , int >  ans ; 
    // base case 
    if (!root ){
        ans.first = 0 ; 
        ans.second =0;
        return ans ; 
    }

    // recursive case 
    pair<int , int > leftCheck = find(root->left) ; 
    pair<int, int> rightCheck = find(root->right) ;

    ans.second = max(leftCheck.second , rightCheck.second) + 1; 

    if (leftCheck.second>rightCheck.second){
        ans.first =leftCheck.first  + root->data;
    }
    else if (leftCheck.second<rightCheck.second){
        ans.first = rightCheck.first + root->data;

    }
    else{// both have equal height 
    ans.first = max(leftCheck.first , rightCheck.first) + root->data ;
        
    }

    return ans ;


}
int sumOfLongestLeaft2Root1 (node* root ){
    // concept : height + max sum 
    pair<int , int > ans = find(root);
    return ans.first ; 


}

// (Approach -2 ) function for find the root to leaf longest sum path and value 
void solve(node* root , int len , int &maxLen , int sum , int &maxSum ){
    // base case 
    if (!root ){
        if (len>= maxLen){
            maxLen = len ; 
            maxSum = sum ; 
        }
        
        return ;
    }

    // Recursive Case 

    sum = sum + root->data;
    solve(root->left, len  + 1 , maxLen, sum , maxSum) ; 
    solve(root->right , len  + 1 , maxLen , sum ,maxSum ) ; 

}
int sumOfLongestLeaft2Root2 (node* root ){

    // concept : nodes Length + maxSum ,maxLength
    // time  : O(n) , space : O((h)->height of the binary tree )

    int len = 0 ; 
    int maxLen =0 ; 
    int sum =0 ; 
    int maxSum = INT_MIN  ; 
    solve(root, len , maxLen , sum , maxSum ) ; 

    return maxSum;

    

}


int main(){
    node* root ; 
    levelBuildTree(root);// 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

    cout<<"Sum of Longest root to Leaf path is : "<<sumOfLongestLeaft2Root1(root) <<endl;
    cout<<"Sum of Longest root to Leaf path is : "<<sumOfLongestLeaft2Root2 (root) <<endl;

    return 0 ;
}
/*
article : 
gfg  : https://practice.geeksforgeeks.org/problems/s um-of-the-longest-bloodline-of-a-tree/1 (done -> o)
code studion : https://www.codingninjas.com/studio/problems/longest-path_3210613?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=SUBMISSION  (done)
interview bit : 
leetcode : 




SIMILIAR QUESTIONS TRY 

https://www.geeksforgeeks.org/problems/sum-of-right-leaf-nodes/1        (done) using level order traversal 
https://www.geeksforgeeks.org/problems/sum-of-left-leaf-nodes/1         (done )using level order traversal 

*/