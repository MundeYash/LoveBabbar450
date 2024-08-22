#include<bits/stdc++.h>
#include<queue>// same header file for the priority queue 
using namespace std ; 

int main (){
    // declaration of priority queue 
    priority_queue<int> maxi ;// this is max heap (by default is max heap )
    maxi.push(1);
    maxi.push(31);
    maxi.push(14);
    maxi.push(11);
    maxi.push(119);
    // printing the max heap 
    int n = maxi.size();
    // this will print in decreasing format 
    for (int i=0 ;i<n ; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    // min heap format 
    priority_queue<int , vector<int> , greater<int>> mini ; 
    mini.push(111);
    mini.push(1);
    mini.push(19);
    mini.push(12);
    mini.push(21);
    int x = mini.size() ; 
     cout<<endl;
     // it will print this is increasing order  format 
    for (int i=0 ;i<x ; i++){
        cout<<mini.top()<<" ";
        mini.pop() ; 

    }
    return 0 ; 
}