#include<bits/stdc++.h>
#include<deque> // header file for the deque 
using namespace std ; 
// DEQUE STL in the c++

int main (){
    // creation of deque 
    deque <int  > d  ; 
    d.push_back(4);// adding elements to deque 

    
    d.push_front(3);
    d.push_front(31);
    // printing element in deque 
    for (auto ch :d){
        cout<<ch<<" ";
    }

    // removing element from deque 
    d.pop_back();
    d.pop_front();
     d.push_front(333);
    d.push_front(313);
    
// to remove the particular element in the deque (by giving the address of inbetween element )
cout<<"The size of the deque is : "<<d.size()<<endl;
d.erase(d.begin() , d.begin()+1);
d.front();

for (auto ch :d){
        cout<<ch<<" ";
    }
 
 // to the size of the deque 
 cout<<"The size of the deque is : "<<d.size()<<endl;

    return 0 ; 
}