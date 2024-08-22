//Boundary Traversal(Important Question ) : Print all the boundary nodes of binary tree in anticlockwise direction 
#include<bits/stdc++.h>
using namespace std; 
class node{
    public: 
    int data ; 
    node* left ; 
    node* right ; 
    // default constructor 
    node(int d ){
        this->data  = d; 
        this->left = NULL ; 
        this->right = NULL ; 

    }

}  ; 

// function for taking the input for level wise 
void buildLevelTree(node* &root ){

    int data ; 
    cout<<"Enter data :"<<endl ; 
    cin>> data ; 
   
   if (data !=-1 ){
     root = new node(data);

   }
   else {
    root = NULL ; 
    return ;
   }
    queue<node* >  q ; 
    q.push(root   );

    while (!q.empty()){
        node* f  = q.front() ; 
        q.pop() ; 



        cout<<"Enter data for left child of :"<<f->data <<endl ; 
        int left ; 
        cin>> left ; 
        
        if (left!=-1 ){
            f->left = new node(left);
            q.push(f->left);
        }


        cout<<"Enter data for right  child of :"<<f->data <<endl ; 
        int right  ; 
        cin>> right ;

        if(right !=-1 ){
            f->right = new node(right);
        
            q.push(f->right);
        } 
    

    }

}
// FUNCTION FOR PRINTING THE LEFTMOSE BOUNDAY NODES EXCEPT THE ROOT NODE    
void leftTraversal (node* root , vector<int> &ans ){
    // base case 
    if (!root )return ; 


    // recursive case (preOrder traversal-> LR N )
    ans.push_back(root->data);

     // other base case (for the leaf nodes )
    if (root ->left == NULL and root ->right == NULL ){
        return ;
    }

   if(root->left){
     leftTraversal(root->left , ans ) ; 
   }
    else{
    leftTraversal(root->right , ans );
    }



}

// function for printing the boundary  leaf nodes 
void leafTraversal (node* root , vector<int>&ans ){
    if(!root )return  ; 
    // printing leaf nodes 
    if (root->left == NULL and root ->right == NULL ){
          ans.push_back(root->data); 
    }




    // recursive case 
    leafTraversal(root->left , ans ) ; 
    leafTraversal(root->right ,ans );


}

// function for printing the rightmost boundary nodes in reverse ordere 
void rightTraversal (node*root , vector<int> &ans ){
    // base case 
    if (!root )return ; 

    // exclude leaf nodes 

    if (root->left == NULL and root ->right == NULL ){
        return ; 
    }
    // recursive caase (postOrder traversal ->LR N)
    
    if (root->right){
        rightTraversal(root->right, ans )  ; 
    }
    else {
        rightTraversal(root->left ,ans );   
    }

    // wapis aatre hue print 
    ans.push_back(root->data);



}
// function for printing the boundary traversal 
vector<int> boundaryTraversal(node* root ){
    // time: O(3n) ,space : O(n)

    vector<int> ans ; 
    if (! root )return ans ; 
    // step 1: print the root node 
    ans.push_back(root->data);

    // step 2 : Print all the leftmost node next after root node and excluding the leaf nodes 
    leftTraversal(root->left ,ans );
    // step 3 Print all the leaf nodes (left + right )
    leafTraversal(root->left ,ans );// left subtree leaf nodes
    leafTraversal(root->right, ans);// right subtree leaf nodes 
    //step 4 : print all the rightmost nodes excluding leaf nodes in reverse order 
    rightTraversal(root->right, ans );

    return ans ;

}

void print(vector<int> ans ){
    for (int i=0 ;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    node* root ; 
    buildLevelTree(root);// 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1

    vector<int> ans = boundaryTraversal(root) ; 
    cout<<"The Boundary traversal is : ";
    print(ans);


    return 0 ;
}

/*
Article : https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/ 
code Studio ; https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_790725?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf  (done)
interview bit : 
leetcode: (done)
gfg : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1 (done)



similiar HOmework question : https://www.codingninjas.com/studio/problems/boundary-sum_790724?interviewProblemRedirection=true (done)
https://www.codingninjas.com/studio/problems/except-boundary_795034?interviewProblemRedirection=true    (done)

https://www.codingninjas.com/studio/problems/boundary-traversal_893063?interviewProblemRedirection=true     (done)
*/