#include<bits/stdc++.h>
using namespace std ;
// TIme Complexity :O(N+M)
// function for comparison of permuations 
bool comparisonPermutatoin (int a[26] , int b[26]){
    for (int i=0;i<26 ;i++){
        if (a[i]!= b[i]){
            return false ;

        }
    }
    return true ;
}

//******************************************************************************
// program to find that permutaion of s1 string exists in s2 string or not (PERMUTAION IN STRING ) 
// all the input string is in lower case character  
bool checkPermuation (string s1 , string s2 ) {//(s1.length() <=s2.length())
int n  = s1.length() ; 
int m = s2.length() ; 

// storing the count of frequency of s1 (smaller string )
int count1[26] ={0};
for (int i=0 ;i<n ;i++){
    int index = s1[i] -'a' ;
    count1[index]++ ;
}


// creating a window of s1 length and check if it exists in s2 or not (window is created in larger s2 string )
int i =0 ; 
int windowSize= n ;
int count2[26] ={0} ;

// work for the first time window 
while (i<n and i<m){
    // storing the count of window characters
    int index = s2[i] -'a' ;
    count2[index]++ ;
    i++ ;

}

if (comparisonPermutatoin(count1 , count2)) return true ;

// I value till here came outside previous window 
// aage check karo new window banake 

while (i<m ){

    // new added character count will update 
    int newChar = s2[i] -'a' ; 
    count2[newChar]++ ;

    // old char which is removed from window , their count will be reduced 
    int oldChar = s2[i-windowSize] ; 
    count2[oldChar]-- ;
    if (comparisonPermutatoin(count1 , count2)) return true ;
    i++ ;

}

// iterated over the whole length of s2 string and not finded any permuation ans 
return false ;


}
int main (){
    string s1 , s2 ; 
    cin>> s2 ;
     cout<<s1<<endl;
     cin>> s2 ; 
   
    cout<<s2<<endl;
    if (checkPermuation(s1, s2)){
        cout<<"Permuation exists "<<endl;
    }
    else {
        cout<<"Not exists "<<endl;
    }
    return  0 ; 
}