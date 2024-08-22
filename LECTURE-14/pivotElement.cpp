#include<iostream> 
using namespace std ; 
 int FindPivot(int a[] , int n ){
    int s=0  , e  = n-1 ; 
    while (s<e){
        int mid = s+ (e-s)/2 ; 
        if (a[mid]>= a[0]){
            s = mid + 1 ; 
        }
        else {
            e = mid ; 
        }
    }
     return s ; 
     // or return e ; 
 }
 void input_array(int a[] , int n ){
    for (int i=0; i<n ;i++){
        cout<<a[i]<< " " ; 

    }
    cout<<endl;
 }
int main (){
    int a[] = {3,8,10,1,2} ; 
    int n= sizeof (a) / sizeof (int ) ; 
     cout<<"The Pivot element in the array is at index  : "<<FindPivot(a,n)<<"\nThe Pivot value is : "<<a[FindPivot(a,n)]<<endl;
    cout<<"Finding the PIVOT Element in the array \n" ; 
    return 0 ; 
}
/*

*/