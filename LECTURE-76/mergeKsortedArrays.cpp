#include<bits/stdc++.h>
using namespace std ; 
// IMPORTANT : **************************
// Merge K sorted arrays : we have given n array with k size each and we have merge them and return the final sorted array 

class node{
    public : 
    int data ; 
    int row ; 
    int col ; 

    // default constructor 
    node(int data , int row , int col ){
        this ->data = data ; 
        this ->row = row ; 
        this ->col = col ;
    }

} ; 

// custom comparator 
class comparator{
    public: 

    bool operator  ()  (node* a , node* b ){
        return a->data > b->data;
    }

     


}; 
void input(vector<vector<int>>&arr , int n , int m ){
    for (int i=0 ;i<n ;i++){
        for (int j=0 ;j<m ;j++){
            cin>> arr[i][j];
        }
    }
}

void output(vector<int >&arr , int n  ){
    for (int i=0 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// function for finding the final merge k sorted arrays 

// Approach 1 : Brute force approach 
vector<int>  mergeksorted(vector<vector<int>> arr , int n , int m ){
    // time : O(n*k log (n*k)) ,space : O(n*k)

    // step  1: create an ans array 
    vector<int> ans ; 

    // step 2 :store all the (n*m)elements of the matrix in the ans 
    for (int i=0 ;i<n ;i++){
        for (int j=0 ;j<m ;j++){
            ans.push_back(arr[i][j]) ;
        }
    }

    // Step 3 : sort the array and return the final sorted arrays 

    sort(ans.begin() , ans.end()) ; 

    return ans;


}

// optimised Approach 2 : 
vector<int> mergeKsoretedArrays(vector<vector<int>> arr , int k ){
    // concept : priority_queue (min heap , custom comparator )

    // time : O(n*k * Log (k)  , space : (k))

     // Step 1 : create of priority queue (min ) and custom comparator for own declared node 
    priority_queue<node* ,vector<node* > , comparator> pq; 

    // Step 2 : Push all the starting value(node) of all the (k)vectors in the priority queue 
    for (int i=0 ;i<k ;i++){
        node* temp = new node(arr[i][0] , i , 0 ) ;
        pq.push(temp) ; 

    }

    // step 2 : (top value ): smallest of priority queue is added in the answer vector 
    vector <int  > ans ; 
    

    while (!pq.empty()){
        node* temp = pq.top() ; 
        ans.push_back(temp->data ) ; 
        pq.pop();
    int i= temp->row ; 
    int j = temp->col ;
        // just greater or next of selected top element is added in the priority queue 
        if (j+1 <arr[i].size()){
            node* next = new node(arr[i][j+1], i , j+1  );
            pq.push(next);
        }
    } 

    return ans;

   
}

int main (){
    int k =3 ; 
    int n=5 ; 
    vector<vector<int>>arr (k,vector<int>(n));

    // take input of the array 

    input(arr ,k,n );
    vector<int > ans = mergeksorted(arr , k , n ) ;

    output(ans , ans.size()); 


    return 0 ; 
}
/*
article : https://takeuforward.org/data-structure/merge-k-sorted-arrays/ 
code studio : https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0 (done)
leetcode : 
gfg : https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1 (done )
interview bit : https://www.interviewbit.com/problems/merge-k-sorted-arrays/  (done)

*/