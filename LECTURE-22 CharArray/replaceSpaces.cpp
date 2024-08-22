#include<iostream>
using namespace std ; 
//PROBLEM: Replace all the all the Spaces in the string with  @40
 void replaceSpace(string &s ){
    //T:O(N-> string length ), S:O(1)
    int n = s.length() ;
    string ans="";
    for (int i=0 ;s[i]!='\0' ;i++){
        
        if (s[i] ==' '){
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
        else{
            ans.push_back(s[i]) ;

        }
        

    
    }
    s = ans ;
 }

int main (){

string s; 
getline(cin,s) ;
cout<<s<<endl;
replaceSpace(s) ;
cout<<s<<endl;
}