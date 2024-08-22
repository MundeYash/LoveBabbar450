#include<iostream>
using namespace std  ; 
int main (){
    int n = 5 ; 
    int count =1 ;

    
    // square pattern  
    for (int i=1 ;i<= n ;i++){
        for (int j=1 ;j<=n ;j++){
            // cout<< char (j+'A'-1) ; 
            // cout<<char (count + 'A'-1 ) ; 
            // count ++ ; 
             cout<<char (i+j-2 +'A') ; 
        }
        cout<<endl;
    }

    // triangle pattern 
    // for (int i=1 ;i<= n ;i++){
    //     int value =  n - i + 'A' ; 
    
    //     for (int j=1 ;j<=i ;j++){
            
    //         // cout<<char (i+j+'A' - 2) ; 
    //         // cout<< char (value)  ; 
    //         // value ++ ; 
    //         cout<<i+j-1 ; 
          
    //     }
    //      cout<<endl;
    // }
     cout<<"This is pattern questions " ; 
    return  0 ; 
}