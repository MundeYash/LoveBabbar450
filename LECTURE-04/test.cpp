#include<iostream>
using namespace std ; 
int main(){
    int n=5  ; 
    // for (int i=1 ;i<=n ;i++){
    //     for (int j=1 ;j<=n ;j++){
    //         if (i==1 || i==n ||j==1 ||j==n){
    //             cout<<"*";
    //         }
    //         else {
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

for (int i=1 ;i<=n ;i++){
    for (int j=n-i; j>=1 ;j--){
        cout<<"  ";
    }
     int value = i  ; 
    for (int j=1 ;j<=i ;j++){
        cout<<value <<" ";
        value -- ;
    }

     int info = 2 ; 
     for (int j=1 ;j<=i-1 ; j++){
        cout<<info<<" ";
        info++ ;
     }


    cout<<endl;
}
    
    return 0 ; 
}