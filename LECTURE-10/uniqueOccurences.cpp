#include<bits/stdc++.h>
using namespace std ; 
// if the number of occurneces of elements in the array is unique return true else return false 

bool uniqueOccurences(vector<int>&a ){
    int n = a.size() ;

    // Approach : use :-> map and set 
    unordered_map<int , int > m ; 
    for (int i=0 ;i<n ;i++){
        m[a[i]]++ ;
    }

    // then inserting the map values :-> occurences of array elements into the set 
    set<int> s1 ; 

    for (int i=0 ;i<n ;i++){
        s1.insert(a[i]) ;
    }

    set<int> s2 ;

    for (auto it= m.begin() ; it!= m.end() ;it++){
        s2.insert(it->second);
       

}

if (s1.size() == s2.size()) return true ;
return false ;
}
int main(){
vector<int> a={-3 ,0 ,1 ,-3 ,1,1,1,-3 ,10,0}; 
int n = a.size() ;
if (uniqueOccurences(a)){
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
    return 0 ;
}