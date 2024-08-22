
#include<bits/stdc++.h>
using namespace std ; 

// structure of the tree
class node
{
public:
    int data;
    node *left;
    node *right;

    // default contructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


// Recursive function for building the tree
node *createTree(node *root)
{ // this function will take the input in preOrder traversal format

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
//******************************************************************

// function for the PreOrder traversal
void preOrder(node *root)
{
    if (!root)
        return;

    // format : (NLR)-> node print , left , right
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// function for finding the morris traversal (PREORDER )
void morrisPre(node* root , vector<int>&ans ){
    // base case 
    if (!root )return ; 

    // 2 pointers ki need 
    node* pre , *curr ; 

    curr = root ; 

    while (curr != NULL ){

        if (curr ->left == NULL ){
            // cout<<curr->data<<" ";
            ans.push_back(curr->data);
            curr = curr ->right ;
        }
        else{
            pre = curr-> left ;

            while (pre->right != NULL and pre->right != curr){
                pre =pre ->right ;
            }

            if (pre->right == NULL ){

                // cout<<current->data <<" ";
                    ans.push_back(curr->data);
                    pre->right = curr ; 
                    curr = curr->left;
                }
                else{
                    // means pre->right == current (again add the null )
                    pre->right = NULL ;

                    
                    curr = curr->right ;

                }
        }

    }

}


vector<int> morrisPreorder(node* root ){
    vector<int> ans ;
    // base case 
    if (!root )return ans ;

    // other solvable case 
    morrisPre(root, ans) ;

    return ans;
}

//*************************************************************************
// function for the morris traversal (INORDER )
void morris(node*root , vector<int> &ans ){
    if (!root )return ;


    // // two pointers are there 
    node * pre  ; 
    node* current ; 

    // // step1 : point the curr to root node 
    current = root ; 

    while (current  != NULL ){
        if (current->left == NULL ){
            // cout<<current->data<<" ";
        ans.push_back(current->data);
        current = current->right ;
        }
        else{

            pre = current->left ; // find predecessor of the current node 

            while (pre->right != NULL and pre->right != current){
                pre = pre->right ; 

               
            }
             if (pre->right == NULL ){
                    pre->right = current ; 
                    current = current->left; 
                }
                else{
                    // means pre->right == current (again add the null )
                    pre->right = NULL ;

                    // cout<<current->data <<" ";
                    ans.push_back(current->data);
                    current = current->right ;

                }

        }
    }

    
 
}


// MORRIS TRAVERSAL FOR (INORDER )
vector<int> morrisTraversal (node* root ){
    vector<int> ans ; 
    if (!root )return ans ;

    // recursive case 
    morris(root , ans );
    return ans;

}


// function for the Inorder  traversal
void inorder(node *root)
{
    if (!root)
        return;

    // format : (LNR)->  left ,node print , right

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void print(vector<int>ans ){
    int n = ans.size() ; 

    for (int i=0 ;i<n ;i++){
        cout<<ans[i]<< " ";
    }
    cout<<endl;
}
int main (){
    // i/p -> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     node *root = createTree(root);
    // 1 2 -1 -1 3 -1 -1
    // i/p -> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1


    cout << "Printing the reverse level    order traversal output : " << endl;
    vector<int> ans = morrisTraversal(root);
    inorder(root  );
    cout<<endl<<endl;
    print(ans);

    vector<int> ans2 = morrisPreorder(root) ; 
    cout<<endl<<endl<<endl;
    print(ans2) ; 
    cout<<endl;
    preOrder(root);
 
    return 0 ; 
}





/*
code studio : https://www.codingninjas.com/studio/problems/preorder-binary-tree_5948
leetcode : https://leetcode.com/problems/binary-tree-inorder-traversal/
gfg : https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
interview bit : 



*/