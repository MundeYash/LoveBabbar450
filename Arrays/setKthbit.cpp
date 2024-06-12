// date -06 December 2023 (Set the Kth Bit of the given integer  )

#include<bits/stdc++.h>
using namespace std ; 

int setKthbit(int n , int k  ){
    int mask = 1<<k ; 

    return (mask|n);

}

int main (){
    int n ; 
    cout<<"Enter the number "<<endl;
    cin>> n ; 

    int k ; 
    cout<<"The k bit would be "<<endl; 
    cin>>  k ; 

    cout<<"The number is "<<n <<endl ;
    cout<<"The number after the setting the kth bit is "<<setKthbit(n,k)<<endl ;
    return 0 ; 
}
/*
Set the Kth Bit of the given integer

Leetcode : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/  (rem )
codestudio : 
gfg : https://www.geeksforgeeks.org/problems/set-kth-bit3724/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article  (done )
interview bit : 


*/