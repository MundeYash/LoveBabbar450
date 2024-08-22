#include<bits/stdc++.h>
using namespace std  ; 
//IMPORTANT QUESTION : (Mostly asked in the Oa and interviews ): Given a binary and we need to find the vertical view of it 
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

// function for Printing the vertical view in the binary tree 
vector<int> verticalView(node* root ){
    // time : O(n* log n ) , space : O(n)
    // base case 
    vector<int> ans ;
    if (!root )return ans ;

    // recursive case 

    // Step1 : creation of map  and queue and pushing of root node 
    map<int , map<int , vector<int> > > nodes ; // (map<int hd , map<int level, vector<int>orderof nodes > > )
    queue< pair<node* , pair<int, int > > >  q; // (queue<pair<node* NODEvalue , pair<int hd , int level> > > q)
    q.push(make_pair(root  , make_pair(0, 0 ))) ; 


    //step2 Work for the queue nodes 
    while (!q.empty()){
         pair<node* , pair<int, int > > frontValue = q.front();
         q.pop();

         node* frontNode = frontValue.first ; 
         int hd = frontValue.second.first ; 
         int level = frontValue.second.second; 

         nodes[hd][level].push_back(frontNode->data);

         // work for the left child 
         if (frontNode->left){
            q.push(make_pair(frontNode->left , make_pair(hd-1 , level+1 )));
         }

         // work for the right child 
         if (frontNode->right){
            q.push(make_pair(frontNode->right , make_pair(hd+1  , level+ 1 )));
         }

    

    }

    // step3 : pushing all the level wise nodes into the answer 

    for(auto i: nodes ){

        for (auto j: i.second){

            // move to the vector 
            for (auto k: j.second){
                ans.push_back(k);
            }
        }
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
  vector<int> ans =   verticalView(root);
  print(ans)    ;

    

    return 0 ;
}

/*

article : https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree/
code studio : https://www.codingninjas.com/studio/problems/vertical-order-traversal_920533?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website         (done)

leetcode : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/(done)
gfg : https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1?page=1&company[]=Dell&sortBy=submissions(done)

interviewbit : https://www.bing.com/ck/a?!&&p=d8ee0529b954b241JmltdHM9MTY5MjgzNTIwMCZpZ3VpZD0xZDNiZTY4YS1kY2I5LTY5MWItMzcyNy1mN2NhZGRiZjY4OWImaW5zaWQ9NTIwMA&ptn=3&hsh=3&fclid=1d3be68a-dcb9-691b-3727-f7caddbf689b&psq=vertical+traversal+binary+trees++gfg+%2c+interviewbit+practice&u=a1aHR0cHM6Ly93d3cuaW50ZXJ2aWV3Yml0LmNvbS9wcm9ibGVtcy92ZXJ0aWNhbC1vcmRlci10cmF2ZXJzYWwtb2YtYmluYXJ5LXRyZWUv&ntb=1(rem)


Similiar Question : 
 https://www.codingninjas.com/studio/problems/vertical-order-traversal_2041990?interviewProblemRedirection=true               (done)
 https://www.codingninjas.com/studio/problems/vertical-sum-in-a-binary-tree_981285?interviewProblemRedirection=true           (done)

 https://www.codingninjas.com/studio/problems/vertical-sum_2100681?interviewProblemRedirection=true         (done)

 https://www.codingninjas.com/studio/problems/nodes-vertically-below-root-node_920756?interviewProblemRedirection=true      (rem)
 https://www.codingninjas.com/studio/problems/vertical-binary-tree_982801?interviewProblemRedirection=true      (done)

 https://www.geeksforgeeks.org/problems/vertical-sum/1          (rem)
 
*/