#include<bits/stdc++.h>
using namespace std ; 
// given an array with n size and we need to check whether we can divide the array into two equal sum values 

            // Method 3:Tabular Method :
        // Method 2 : Memoiazatino 
        bool solveMem(int index , int n , int arr[ ] , int target , vector<vector<int>> &dp){
            
            // base cases 
            // base case
                if (index>=n )return 0 ;
                
                if (target<0 )return 0 ; 
                
                if (target ==0 )return 1 ; 
                if (dp[index][target ]!=-1 ){
                    return dp[index][target ];
                }
            
            // base case
                if (index>=n )return 0 ;
                
                if (target<0 )return 0 ; 
                
                if (target ==0 )return 1 ; 
                
                bool inc = solveMem(index +1 , n , arr , target -arr[index ] ,dp) ; 
                bool exc = solveMem(index + 1 , n , arr , target -0 , dp ) ; 
                
                return dp[index][target ] =  (inc ||  exc );
            
        }

    // helper function :Simple Recursion 
    bool  solve(int index , int n , int arr[] , int target ){
        // base case
        if (index>=n )return 0 ;
        
        if (target<0 )return 0 ; 
        
        if (target ==0 )return 1 ; 
        
        bool inc = solve(index +1 , n , arr , target -arr[index ] ) ; 
        bool exc = solve(index + 1 , n , arr , target -0 ) ; 
        
        return (inc ||  exc );
    }

int main (){
    return 0 ;
}