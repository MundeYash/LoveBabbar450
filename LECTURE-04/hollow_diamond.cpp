#include<iostream>
using namespace std ; 
int main (){
    int n=10 ; 
    int k = 0 ; 

    for (int i=1 ;i<=n ;i++){
         i<=(n/2)+1 ? k++ : k-- ; 
        for (int j=1 ;j<=n ;j++){
           

            if (j<= ((n/2)+2 -k) || j>= (n/2)+k){
                cout<<"*" ; 
            }
            else {
                cout<<" "; 
            }

        }
                    cout<<endl;
    }
    return 0 ; 
}