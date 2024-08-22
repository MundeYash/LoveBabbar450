#include<iostream>
using namespace std ; 
int removeDuplicate (int *a , int n ){
    int i=0 , j=0 ; 
    while(i<n and j<n ){
        if (a[i]!= a[j]){
            j++ ; 
            a[j] = a[i] ; 
        }
        else {
            i++ ; 
        }
    }
     return j+1 ; 
}
void input(int *a  , int n ){
    for (int i=0 ;i<n ;i++){
        cin>> a[i] ; 
    }
}
 void printArray (int *a , int  n){
    for (int i=0 ;i<n ;i++){
        cout<<a[i]<<" " ; 
    }
     cout<<endl;
 }
// leetcode (Remove duplicate in the same array )
int main (){
   
    int a[] ={ 1, 1,2, 3,3,4,4 ,5,10} ; 
     int n  = sizeof (a) / sizeof (int ) ; 
    // cin>> n ; 
    // int * a = new int [n] ; 
    // input(a,n ) ; // non decreasing order mein hona chahiye 

    printArray(a,n ) ; 
    // cout<<"The k value is :"<<removeDuplicate(a, n ) <<endl; 
    int k  = removeDuplicate(a , n ) ; 
     cout<<k<<endl;
    printArray(a,k) ; 


     cout<<"30 november 2022 pratice of array question \n "  ; 

    return 0 ; 
}