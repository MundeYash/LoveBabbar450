#include<iostream>
using namespace std  ; 
// function for Insertion Sort Algorithm 
void insertionSort (int a[] , int n ){

// code remaining 
//In this we have the concept of hand pick card and shifting the values 

for (int i=1 ;i<n ;i++){
    int HPC = a[i] , j ;
    for (j = (i-1);j>=0 ;j-- ){
        if (a[j]>HPC){
            // shifting the values 

            a[j+1]  = a[j];
        }
        else {
            break  ; 
        }
    }
    a[j+1] = HPC ;
}


}

// input for the array 
void input (int a[] , int n ){
    for (int i=0 ;i<n ;i++){
        cin>> a[i] ;
    }
}
// output for the array 
void output (int a[],int n ){
    for (int i=0 ;i<n ;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
// this is all about the insertion sort algorithm 
int main (){
    int n ; 
    cin>> n ; 
    int *a = new int [n] ; 
    input(a , n ) ; 
    output(a,n) ;
    insertionSort(a,n) ;
    output(a,n); 

    return 0 ; 
}