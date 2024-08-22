
#include<bits/stdc++.h  > 
using namespace std ; 

// Minimum time burn the complete tree : using the level order traversal concept ;
// time : O(n logn ), space :O (n)
class node{
    public : 
    int data ; 
    node* left  ; 
    node* right ; 


    // default constructor format 
    node(int d ){
        this ->data =d  ; 
        this    ->left = NULL  ; 
        this ->right = NULL ;
    }


}  ; 

// Function for taking the input in the level order traversal format 
void levelBuildTree(node* &root ){
    // concept : Level order traversal 

    queue<node* > q ; 
    cout<<"Enter the data for the root node : "<<endl ; 

    int data ; 
    cin>> data ; 
    if (data !=- 1 ){
        root = new node(data);

    }
    else{
        // data ==-1 (NULL )value is there 
        root = NULL ; 
        return ;

    }
    q.push(root) ;


    // work for the queue and follow the level order travaral 
    while (!q.empty()){

        node* frontNode = q.front() ; 
        q.pop() ; 


             cout<<"Enter the data for the left of "<<frontNode->data <<endl ; 
            int leftData ; 
            cin>> leftData ; 
           
            if (leftData !=-1 ){

                frontNode->left = new node(leftData) ;
                q.push(frontNode->left);
            }

            // work for the right child 

             cout<<"Enter the data for the right of "<<frontNode->data <<endl ; 
            int rightData ; 
            cin>> rightData ; 

            if (rightData != -1 ){
                frontNode->right = new node(rightData) ;
                q.push(frontNode->right);
            }
        
    }
    return ;



} 
node*  createMapping (node* root , int target , map<node* , node* > &nodeToParent ){

    // concept  :Level order traversal concept 

    queue<node* > q; 
    q.push(root) ; 
    nodeToParent[root] = NULL ; // setting the root parent to the null 
    node* result = NULL ; 

    // work for the queue 
    while (!q.empty()){
        node* frontNode = q.front() ; 
        q.pop() ; 

        if (frontNode->data == target){
            result = frontNode ;

        }

        // set parent mapping  

        if (frontNode->left){
            nodeToParent[frontNode->left] = frontNode ;
            q.push(frontNode->left);
        }

        if (frontNode->right){
            nodeToParent[frontNode->right]  = frontNode;
            q.push(frontNode->right);
        }

    }

    return result ;

}

// function for burn tree 
int burnTree(node* root , map<node* , node* >nodeToParent){

    int  ans =0 ; 

    // concept Applied : Level Order Traversal 
    map<node* , bool > visited  ; 

    queue<node* > q ; 
    q.push(root) ; 
    visited[root]= 1; 


    while (!q.empty()){
       
       int size =q.size() ; 
       bool flag = false ;

       for (int i=0 ;i<size ;i++){
         // applying the bfs from the target node 

        node* frontNode = q.front() ; 
        q.pop( ) ;
        // 3 direction checking (left , right , parent check )

        // left direction 
        if (frontNode->left and !visited[frontNode->left]){
            q.push(frontNode->left )    ;
            visited[frontNode->left] = 1 ; 
            flag = true  ;

        }

        // right direction 
        if (frontNode->right  and !visited[frontNode->right]){
            q.push(frontNode->right )    ;
            visited[frontNode->right] = 1 ; 
            flag = true  ;

        }


        // parent uppward direction check 
        if (nodeToParent[frontNode] and !visited[nodeToParent[frontNode]]){
            q.push(nodeToParent[frontNode]); 
            visited[nodeToParent[frontNode]] =1 ; 
            flag = 1  ; 
        }

          }


        if (flag == true ){// addition of a node in the queue 
            ans ++ ; 
        }

    }

    return ans ; 
}
// Function for finding the minimum time to burn the complete tree 
int completeBurnTree(node*root , int target ){

    // step 1 : Creation of mapping with the parent 
    map<node* , node* > nodeToParent ; 

    // ste2p : find the location of node where value is target value 
    node* targetNode = createMapping(root , target , nodeToParent);

    // step 3 : Start burn the target node and find min time to burn the tree 

    int ans = burnTree(targetNode, nodeToParent);
    return ans ;



}
int main (){
    node* root ; 
    levelBuildTree(root) ;// 1 3 5 7 11 17  -1 -1 -1 -1 -1 -1 -1
    int target = 3 ;
    cout<<"The minimum time to burn the compelete tree  from node->"<<target<<" is:"<<completeBurnTree(root, target)<<endl;


    return 0 ;
}
/*
Question : Minimum time to burn the complete tree if start the fire from the target node and at every 1 sec all connected nodes gets burned 

//1 5 3 -1 4 10 6 9 2 -1 -1 -1 -1 -1 -1 -1 -1 

leetcode : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/  (done)
gfg ;https://practice.geeksforgeeks.org/problems/burning-tree/1 (done)
code studio : https://www.codingninjas.com/studio/problems/time-to-burn-tree_1469067  (rem)


homework try : https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1

*/