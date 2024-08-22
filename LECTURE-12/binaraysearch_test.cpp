#include<iostream>
using namespace std ; 
 int Binary_search(int a[] , int n , int key ){
    // starting and ending index 
    int start =0 , end = n-1 ; 

    while (start<=end ){
            //  int mid = (start + end)/ 2 ; 
            // modified form for upper limit in range 
             int mid = start + (end-start)/2 ; 
           // if key == array element at mid 
        if (key == a[mid]){
            return mid ; 

        }
        // if array value at mid index is Greater than key 
        else if (key>a[mid]){
            start = mid + 1; 

        }
        else  {
            end = mid - 1; 

        }
        
    }
     return -1 ; 
 

 }
 void print_array (int a[] , int n ){
    for (int i=0 ;i<n ;i++){
        cout<<a[i]<<" " ; 
    }
    cout<<endl ; 
 }
int main (){
    int a[] = {2,5,6,7,8,10,100} ; 
    int n = sizeof (a) / sizeof (int) ; 
print_array(a,n) ; 

//  cout<<"The index is present at: "<<Binary_search(a,n,1) <<endl ; 
if (Binary_search(a,n,10)==-1){
    cout<<"Key is not Present \n" ; 
}
else {
    cout<<"Key is present at : "<<Binary_search(a,n,10) <<endl;
}

     cout<<"This is the Program about Binary Search in C++\n"  ; 
    return 0 ; 
}