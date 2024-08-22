#include<bits/stdc++.h>
using namespace std ; 

// checking a number is prime number or not 

int main (){
    int n  ; 
    cin>> n  ; 
     bool check =1 ; 
    for (int i=2 ;i<n ;i++){
        if (n%i == 0 ){
            check = false ; 
            cout<<"Non Prime "<<endl;
            break ; 
        }
    }
     if (check == 1){
        cout<<"Prime Number "<<endl;
     }
    
    return 0 ; 
}