#include<iostream>
using namespace std ; 
// Bubble Sort algorithm implementation 
void bubbleSort (int a[] , int n ){
    // At every iteration we are placing the our largest element at their position 
    for (int i=0 ;i<n-1  ;i++){
        for (int j=0 ;j<n-1  ;j++){
            if (a[j+1]<a[j]){
                swap(a[j] , a[j+1]);// swappting the values 
            }
        }
    }

}

// function for the optimised bubble sort 
void bubbleSortOptimised  (int a[] , int n ){
    bool swapedCheck =false ;
    for (int i=0 ;i<n-1 ;i++){
        for (int j=(0) ;j<(n-i-1) ;j++){
            if (a[j+1]<a[j]){
                swapedCheck = true ;
                swap(a[j]  , a[j+1]) ;
            }
        }
        if (swapedCheck == false){
            // means ek bar bhi swappng nhi hui matlab array already sorted h 
            break ;

        }
    }
}
// function for getting input 
void input (int a[] , int n ){
    for (int i=0 ;i<n ;i++){
        cin>>a[i];
    }
}

// function for displaying input 
void output (int a[] , int n ){
    for (int i=0 ;i<n ;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main (){
    int n ; 
    cin>> n ; 
    int *a = new int [n] ;
    input(a,n);
    output(a,n);
    bubbleSort(a,n);
    output(a,n);
// 5 100 0 -1 5 4 

    return 0 ;
}