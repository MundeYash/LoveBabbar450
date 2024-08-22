#include<iostream>
using namespace std ; 
// this is the home work pattern question 
int main (){
    int n =9; 
    // cin>> n  ;  
    
    for (int i=1 ;i<= n ;i++){

        // 1st part 
        for (int j=1 ;j<=n-i+1  ;j++){
            cout<<j<<" ";
        }

        // spaces printing 
        for (int j=1 ;j<= i-1 ;j++){
            cout<<"* ";
        }
        for (int j=1 ;j<= i-1 ;j++){
            cout<<"* ";
        }
        
        // 3 rd part 
        for (int j=n-i+1 ;j>=1 ;j--){
            cout<<j<<" ";
        }

        cout<<endl;
    }
    return 0 ; 
}