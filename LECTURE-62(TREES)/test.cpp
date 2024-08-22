#include<iostream>
#include<queue>
using namespace std ; 
// Trees - binary trees :- the nodes in the trees  having at most 2 children 
class node{
     public : 

     int data  ; 
     node* left ; 
     node* right  ; 

     // default constructor calling 
     node(int d)
     {
        data = d ; 
        left = NULL ; 
        right = NULL ; 
     }

     

} ; 
// function for creating the tree in general format 

     node* buildTree(node* root ){
        int data ; 
        cout<<"Enter the  data "<<endl;
        cin>> data ; 
        root = new node(data) ; 
        if (data == -1 ){ // means it points to null 
             return NULL ; 

        }
        // data has some value that it means it left and right child exits 
        cout<<"Enter the data for inserting in left of  "<<data<<endl;
        root->left = buildTree(root ->left) ; 
        cout<<"Enter the data for inserting in right of  "<<data<<endl; ; 
        root -> right = buildTree (root ->right) ; 
        return root ; 

     }

     // function for the level-order traversal in the tree
     void level_order (node* root ){
        queue<node* > q ; 
        q.push(root) ; 
        q.push(NULL) ; 

        while (!q.empty()){

            node* temp = q.front() ; 
            q.pop() ; 
            if (temp == NULL){
                // means previous level complete ho chuka h and go to next line 
                cout<<endl  ; 
                if (!q.empty()){
                    q.push(NULL) ; 
                }
            }
            else{ // means some elements in the queue then print it 
            cout<<temp->data <<" " ; 

            if (temp->left){
                q.push(temp->left) ; 
            }
            
            if (temp->right){
                q.push(temp->right) ; 
            }

            }
        }

     }
     // Function for PreOrder Traversal 

     void preOrder (node* root ){ //root R , left child L , right child R 
        // base case 
        if (root == NULL ){
            return ;
        }
         cout<<root->data<<" " ; 
         preOrder(root->left) ; 
         preOrder(root->right) ;



     }
     // function for inOrder Traversal lNR
     void inOrder (node* root ){
        if (!root ){
            return ; 
        }
        inOrder(root->left) ; 
        cout<<root->data<<" " ; 
        inOrder(root->right) ;

     }
     // function for post order traversal LRN
     void postOrder (node* root ){
         if (!root ){
            return ; 
        }
        postOrder(root->left ) ; 
        postOrder(root->right) ; 
        cout<<root->data<<" " ; 

     }
      
      // Function for Creating tree in level order wise 
      void levelBuildTree(node* &root ){
        queue<node* > q ; 
        cout<<"Enter the data of root "  <<endl;
        int data ; 
        cin>> data ; 
        root = new node (data)   ;  
        q.push(root) ; 

        while (!q.empty()){

            node* temp = q.front() ; 
            q.pop() ; 
     // for left node of the temp 
        cout<<"Enter the left node "<<temp->data  <<endl  ; 
        int left_data ; 
        cin>> left_data ; 
        if (left_data != -1 ){
        temp->left = new node (left_data) ; 
        q.push(temp->left) ; 

        }
        // for right node of the temp 

         cout<<"Enter the right  node "<<temp->data <<endl  ; 
        int right_data  ; 
        cin>> right_data ; 
        if (right_data != -1 ){
        temp->right = new node (right_data) ; 
        q.push(temp->right) ; 

        }
        }


      }
int main (){

    node* root = NULL ; 
    // root = buildTree(root) ; // input for given tree : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 // another tree : 1 2 5 -1 -1 6 -1 -1 3 -1 -1 

    // creating tree through levelOrder  
    levelBuildTree(root ) ; // input format: 1 3 5 7 11 17 -1  -1 -1  -1 -1  -1 -1 
     cout<<"Printing level Order traversal :"<<endl ; 
     level_order(root) ;
     
     cout<<"This is for preOrder traversal "<<endl;
     preOrder(root) ; 
     cout<<"\nThis is for INOrder traversal "<<endl;
     inOrder(root) ; 
     cout<<"\nThis is for PostOrder traversal "<<endl;
     postOrder(root) ; 
     cout<<"\nThis is starting lecture of trees" ; 

    return 0 ; 
}