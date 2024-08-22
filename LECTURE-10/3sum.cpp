#include<bits/stdc++.h>
using namespace std ; 
// 3Sum question : 
void threeSum(vector<int>&a , int n , int target  ){
    for (int i=0 ;i<n-2 ;i++){
        for (int j=(i+1) ;j<n-1 ;j++){
            for (int k =(j+1) ;k<n ;k++){
                int sum = a[i] +a[j] + a[k ] ; 
                if (sum == target ){
                     cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<"\n";

                  
                   

                }
            }
        }

    }

}
int main(){
    vector<int>a = {10 ,5 ,5 ,5 ,2} ;
    sort(a.begin() , a.end());
    int n = a.size() ; 
    int k = 12 ;
   threeSum(a,n,k);


    return 0 ;
}

/*
 CODE STUDIO : https://www.codingninjas.com/studio/problems/triplets-with-given-sum_893028?topList=love-babbar-dsa-sheet-problems (REM)
 GFG : https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1 (REM)
*/