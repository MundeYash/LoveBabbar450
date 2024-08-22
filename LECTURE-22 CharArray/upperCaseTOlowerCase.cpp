#include<iostream>
using namespace std ; 
// function for converting the upper case to lower case 
char conver(char ch ){
    return (ch-'A'+'a');
}
// function for converting the lower  case to Upper  case 
char convert(char ch ){
    return (ch-'a'+'A');
}




int main (){
    char ch ; 
    cin>> ch ;
    cout<<"Before :"<<ch<<endl;
    // cout<<"after  :"<<conver(ch)<<endl;
    cout<<"AFTer:"<<convert(ch)<<endl;
}