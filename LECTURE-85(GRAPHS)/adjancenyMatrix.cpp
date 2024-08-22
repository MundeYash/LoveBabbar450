// creation of graph using the adjacency matrix 
#include <iostream>
#include<vector> // header file for the vector 
using namespace std ; 
 class graph {
     public : 
      vector <vector<int >> adj ; 
      


 } ; 
int main (){
    // implementation of adjacency matrix of graph
    
     // adding 0 values to all the buckets 

     int v ; 
      cout<<"Enter the number of vertices "<<endl;
     cin>> v ; 

      vector <vector<int >> ans(v, vector<int>(v,0))  ;  
       int edges    ; 
      for (int i=0 ;i< v ; i++){
        
      
         cout<<"Enter the number of edges for "<<i<<"->vertex" ;
         cin>>edges; 
            
            for (int j =0 ;j<edges;j++){
                int value_edge ;
                cout<<"Enter the  value of connecting edges for "<<i <<endl ;
                cin>> value_edge ; 
                ans[i][value_edge] = 1 ; 
            }
      }

      // printing the adjacency matrix 
      for (int i=0 ;i<v   ; i++){
        for (int j = 0 ; j< v; j++){
            cout<<ans[i][j]<<" ";

        }
         cout<<endl;

      }
    return 0 ; 
}
/*
GFG : https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1 (done);
code studio  : 
leetcode 
*/