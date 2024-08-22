#include<iostream>
using namespace std ; 
// finding the total number of occurences in the array 
int first_occur(int a[] , int n , int key ){
    int start =0 , end = n -1  , ans =-1  ; 
    while (start <= end ){
        int mid = start + (end -start) /2 ; 
        if (key == a[mid]){
            ans = mid ; 
            // left most ke liye left aur check karlo ek bar (for confirmation )
            end = mid - 1 ; 
          

        }
        else if (key>a[mid]){
            start = mid + 1; 

        }
        else {
            end = mid - 1 ; 
        }
    }
     return ans  ; 

}
int last_occur(int a[] , int n  , int key ){
int start =0 , end = n -1 , ans =-1   ; 
    while (start <= end ){
        int mid = start + (end -start) /2 ; 
        if (key == a[mid]){
             ans = mid ; 
            // right most ke liye right aur check karlo ek bar (for confirmation )
           start = mid + 1  ; 
            
        }
        else if (key>a[mid]){
            start = mid + 1; 

        }
        else {
            end = mid - 1 ; 
        }
    }
     return ans ; 
}

// CONCEPT: BINARY SEARCH (lastOccurence Index  - First Occurence Index )
int main (){

     int a[] ={0,0,1,1,1,1,2,2,2,2,2,3} ; 
    int n = sizeof (a) / sizeof (int) ; 
    int ans = last_occur(a,n,2)- first_occur(a,n,2) + 1  ; 
     cout<<"The number of Occurence is : "<<ans <<endl;
    return 0 ; 
}