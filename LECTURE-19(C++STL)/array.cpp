#include<iostream>
using namespace std ; 
// header file for the array 
#include<array>
int main (){
    // create of array via stl 
    array<int , 4 > a={2,3,3,4} ; // keyword <datatype, size> name 

array<char, 5> ch ; 
// input in the array 
 for (int i=0 ;i<5 ; i++){
     cin>>ch.at(i);
 }
 cout<<"Output is : "<<endl;
  for (int i=0 ;i<ch.size() ; i++){
    cout<<ch[i]<<" ";
    
  }
  cout<<endl;
    // priting the array 
    for (int i=0 ;i<a.size() ; i++){
        cout<<a.at(i)<<" ";
    }
    // to get front element 
    cout<<ch.front()<<endl;
    // to get last element 
    cout<<*(a.end())<<endl;



}