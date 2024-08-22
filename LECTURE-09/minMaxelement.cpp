#include<bits/stdc++.h>
using namespace std ; 
int maxElement(int a[]  , int n ){
    int maxi = INT_MIN ; 
    for (int i=0 ;i<n ;i++){
        if (a[i]>maxi){
            maxi = a[i] ;
        }
    }
     return maxi ;
    
}

int minElement(int a[]  , int n ){
    int mini = INT_MAX ; 
    for (int i=0 ;i<n ;i++){
        if (a[i]<mini){
            mini = a[i] ;
        }
    }
     return mini ;
    
}
void input (int a[]  , int n ){
    for (int i=0 ;i<n ;i++){
        cin>>a[i] ;
    }
}
void output (int a[]  , int n ){
    for (int i=0 ;i<n ;i++){
        cout<<a[i]<<" " ;
    }
    cout<<"\n";
}
int main (){
    int n ; 
    cin>> n ; 
    int *a = new int [n] ; 
    input(a,n);
    output(a,n);
   cout<<"The maximum element in the array is : "<< maxElement(a, n ) <<endl; 
   cout<<"The minimum  element in the array is : "<< minElement(a, n )<<endl ; 
   

 
}