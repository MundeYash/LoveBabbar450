#include<bits/stdc++.h>
using namespace std ; 
// Reverse a given string 
 int  length (string s ){
    int count =0 ; 
    for (int i=0 ;s[i]!='\0' ;i++){
        count++ ;
    }
    return count ;
 }



 //Appraoch 2 : T:O(N)
void reverse (string &s ){
    int st=0 , e = length(s) -1 ;
    while (st<=e){
        swap(s[st++] ,s[e--] ) ;
    }


}
int main (){
    string s ; 
cin>> s;
 cout<<s <<endl;
 reverse(s) ;
 cout<<s ;
    return 0 ;
}