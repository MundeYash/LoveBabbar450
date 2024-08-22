#include<bits/stdc++.h> 
#include<queue>// header file for the priority queue stl 
using namespace std ; 

int main (){
    priority_queue<int> pq ; // max heap 
    pq.push(30);
    pq.push(3);
    pq.push(31);
    pq.push(13);
    pq.push(33);
 

 // operation / functions : push , pop , top , size , is empty 
 cout<<"Top element is : "<<pq.top() <<endl; 
 pq.pop() ; 

 cout<<"The size is : "<<pq.size() <<endl;

 cout<<pq.empty()<<endl;


 priority_queue<int , vector<int >, greater<int > > pq1  ; 

 pq1.push(30);
    pq1.push(3);
    pq1.push(31);
    pq1.push(13);
    pq1.push(33);
 

 // operation / functions : push , pop , top , size , is empty 
 cout<<"Top element is : "<<pq1.top() <<endl; 
 pq1.pop() ; 

 cout<<"The size is : "<<pq1.size() <<endl;

 cout<<pq1.empty()<<endl;


}