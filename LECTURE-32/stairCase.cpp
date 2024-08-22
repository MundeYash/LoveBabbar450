#include<bits/stdc++.h>
using namespace std ; 
// find The ways to reach the nth Stair from source to destination (condition you can either jump to one above staircase or two above staircase )
// time  : O(exponential = 2^n) ,space : O(n) 

int NthStairCase ( int n  ){
    if (n<0) return 0 ;

    if (n==0 ) return 1 ;

    return NthStairCase(n-1) + NthStairCase(n-2) ;
}
int main(){
    int n  =5  ; 
    // cin>> n ; 
    cout<<"The Ways to reach the nth staircase is : "<<NthStairCase(n)<<endl;


    return 0 ; 
}