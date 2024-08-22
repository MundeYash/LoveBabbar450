#include<bits/stdc++.h>
using namespace std  ; 

//Question :Kth smallest Element in the array : 

//Brute force : Sorting and k-1 index return 
int Ksmallest1(vector<int>arr , int k) {
    // time : O(n log n ) , space : O(1)
    
    int n = arr.size() ; 

    // step 1 : sort the array 
    sort(arr.begin() , arr.end()); 

    // step 2 : kth smallest is present at the k-1 index 
    return arr[k-1];

}

// optimised approach : Priority_queue(max heap)

int Ksmallest2(vector<int>arr , int k ){
    int n =arr.size() ; 
 // // step 1: push the first k elements of array into the max heap 
        priority_queue<int> h ; 
        
        for (int i=0 ;i<k ;i++){
           
            h.push(arr[i]) ;
        }
        
        // step 2: for the remaining n-k element or (k to n-1 ) index : if they are smaler than heap elements push them into the heap 
        for (int i=k;i<n ;i++){
            if (arr[i]< h.top()){
                 h.pop();
                h.push(arr[i]) ;
            }
        }
        
        // now only k elements will be in the heap 
        return h.top();

}



// optimised approach 2:Solving using the min heap 
int Ksmallest3(vector<int>arr , int k ){
    int n =arr.size() ; 
 // Approach : using the Min heap 
        priority_queue<int , vector<int>, greater<int>> pq ; 
        
        // step 1 : push all the elements 
        for (int i=0 ;i<n ;i++){
            pq.push(arr[i]) ;
            
        }
        
        // step 2 : remove the k-1 elements from the top of the heap 
        for (int i=1 ;i<k;i++){
            pq.pop() ;
        }
        return pq.top();

}
int main (){
    vector<int>arr = {1,22,11,10,9} ; 
    int n = arr.size() ; 
    int k =3 ;

    cout<<"The Kth smallest element is : "<<Ksmallest1(arr,k)<<endl;
    cout<<"The Kth smallest element is : "<<Ksmallest2(arr, k )<<endl;
    cout<<"The Kth smallest element is : "<<Ksmallest3(arr, k )<<endl;
    return  0 ; 
}

/*
leetcode : 
gfg : https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1 (done)

code studio : https://www.codingninjas.com/studio/problems/kth-smallest-integer-in-ranges_1115609?leftPanelTab=0&count=25&page=3&search=kth&sort_entity=order&sort_order=ASC (rem m)
interview bit : 
*/