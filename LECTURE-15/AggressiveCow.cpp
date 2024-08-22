#include<bits/stdc++.h> 
using namespace std ; 

// Aggressive Cow Problem no  - 150 Code Studio 

int maxi(vector <int>&a , int n  ){
    int ans =-1 ; 
    for (int i=0 ;i<n ;i++){
        if (a[i]>ans ){
            ans = a[i] ; 
        }
    }
     return ans ; 
}
bool check(vector <int>&a , int n , int mid , int k ){
    int cowCount =1 ; 
    int lasPos = a[0] ; 
     for (int i=0 ;i<a.size() ; i++){
         if (a[i] - lasPos >= mid  ){
             cowCount ++ ; 
             if (cowCount == k ){
                 return true ; 
             }
              lasPos =a [ i ] ; 
}
     } 
     return false ; 

}
int aggressiveCows (vector<int>&a , int n , int k ){
    int s=0 , e= maxi(a , n ) ; 
    int ans =-1  ; 
    while (s<=e ){
        int mid = s+ (e-s) /2 ; 
        
        if (check(a,n , mid , k)){
            ans = mid  ; 
            s = mid + 1; 
        }
        else {
            e = mid - 1 ; 
        }
    }
     return ans ; 

}
int main (){
    int n ; 
    cin>> n ; 
    int m ; 
    cin >> m ; 
    vector <int > stalls ; 
    stalls.push_back(4) ; 
    stalls.push_back(2) ; 
    stalls.push_back(1) ; 
    stalls.push_back(3) ; 
    stalls.push_back(6) ; 
     for (int i=0 ; i<n ;i++){
        cout<<stalls[i] <<" "; 
     }
     // we need sort value for finding the min diff 
     sort(stalls.begin() , stalls.end()) ; 
      cout<<endl;
       
      cout<< aggressiveCows(stalls , n , m) ; 

     cout<<"\nThis is Aggressive Cow Problem using Binary Search \n" ; 
    return 0 ;
}