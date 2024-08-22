#include<bits/stdc++.h>
using namespace std ; 

// IMPORTANT : **************************
// date -23 october 23 before dussera 
// Merge K sorted link list : given (k) number of sorted link list and we need to return the single merged sorted link list 
class node{
     public: 
     int data ; 
     node* next ; 


     // default constructor 

     node(int d ){
        this ->data =d ; 
        this ->next = NULL ;
     }


    
};


// Brute force : 
node* mergeKsortedLL1(vector<node* > arr , int k ){
    // concept : store all node and array to link list conversion 
    // time : (n*k Log (n*k)), space : O(n*k)


    //step 1 : store all the element of k number of link list in some array 

    vector<int> ans ; 
    for (int i=0 ;i<k ;i++){

        node* head = arr[i];
        while (head != NULL ){
            ans.push_back(head ->data ) ;

            // update the head (move the iterator )

            head = head ->next ; 


        }
    }

    // step 2 : array to link list creation 
    node* dummy = new node(0) ; 
    node* temp = dummy   ; 

    for (int i=0 ;i<ans.size() ; i++){
        node* newnode = new node(ans[i]) ; 
        temp->next = newnode ;
        temp = temp->next ;
    }

    return dummy->next ;

}


// optimised approach : 

node* mergeKsortedLL2(){
    // time : O(n*k log(k)) , space : O(k)
// remaining code 

}
int main (){
    return 0 ;
}

/*
Article : 
code studio: https://www.codingninjas.com/studio/problems/merge-k-sorted-lists_992772?leftPanelTab=0 (rem )
interviewbit ; https://www.interviewbit.com/problems/merge-k-sorted-lists/  (done ->b )
gfg : https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1  (rem )
leetcode :  https://leetcode.com/problems/merge-k-sorted-lists/description/  (rem )

*/