#include<iostream> 
using namespace std ; 

 int BinarySearch (int a[] , int s , int e , int key){
    
    while (s<=e){
        int mid = s + (e-s) /2 ; 
        if (key== a[mid]){
            return mid ; 
        }
        else if (key>a[mid]){
            s = mid + 1; 

        }
        else {
            e = mid - 1; 
        }
    }
     return -1  ; 
 }

 
 int PivotElement(int a[] , int n ){
    int s=0  , e = n-1 ; 
    while (s<e){
        int mid = s+ (e-s)/2 ; 

        if (a[mid]>= a[0]){
            s = mid +1 ; 
        }
        else{
            e = mid  ; 
        }
    }
     return s ; 
 }
 void Print_array(int a[] , int n ){
    for (int i=0 ;i<n ;i++){
        cout<<a[i]<<" " ; 

    }
    cout<<endl;
 }
 int FindPosition(int a[] , int n , int k ){
    int pivot = PivotElement(a,n) ; 
    if (k>=a[pivot] && k<= a[n-1] ){// this is for pivot element to n-1 element 
     return BinarySearch(a,pivot,n-1,k) ;

    }
    else {// this is for 0 element to pivot element 
return BinarySearch(a,0,pivot -1, k) ; 
    }
}
int main (){
    // int a[] = {} ; 
    // int n =sizeof(a) /sizeof(int ) ; 
    int n ; 
    cin>> n; 
    int *a = new int[n ] ; 
    for (int i=0 ;i<n ;i++){
        cin>>a[i];
    }
    Print_array(a,n) ; 
     int k =10 ; 
     
      cout<<"The position after rotation is :"<<FindPosition(a,n,k)<<endl ; 
     cout<<"Search in Sorted And Rotated Array using binary search \n" ; 
    return 0 ; 
}
/*

*/