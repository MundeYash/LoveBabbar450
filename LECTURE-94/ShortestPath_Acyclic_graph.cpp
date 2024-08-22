#include<iostream>
#include<unordered_map>
#include<list> 
#include<vector>
#include<stack>
#include<limits.h>
using namespace std ;
// Code for finding the shortest Path 
/*
logic :- Topological sort find -> linear order -> distance array  se path find ho jayega  

*/


// creation of class graph 
template <typename T> 
class graph{
    public : 
    unordered_map<T, list<pair<T , T>> > adj ; 

    // function for adding edge in the grah 
    void addEdge(T u , T v , T weight )
    {
        // making pair of u and weight 
        pair<T , T > p = make_pair(v , weight) ; 
        adj[u].push_back(p) ; 


    }

    // function for printing the adjacency list 
    void print (){

        for (auto n : adj ){

            cout<<n.first<<":->" ; 
            for (auto ch : n.second ){
                cout<<"("<<ch.first<<","<<ch.second<<") " ; 
            }
            cout<<endl;
        }
    }

    // function for dfs 

    void dfs (int node   , unordered_map<int , bool > &visited , stack<int > &s ){
        visited[node] = true ; 

        // iterating over the childs of node 
        for (auto ch : adj[node]){
            if (!visited[ch.first]){
                // call the dfs func
                dfs(ch.first , visited , s) ; 

            }
        }
        s.push(node) ; 
        



    }
    // function for shortest path 
    void getShortestPath(int src  ,vector<int> &distance , stack<int > &s ) {

            distance[src] = 0 ; // making the distance of source node to zero 
        while (!s.empty()){
            int top = s.top() ; 
            s.pop() ; 
     // iterating over the neighbouring elements 

if (distance[top] != INT_MAX)
{
                    
                
            for (auto i: adj[top]){
                if (distance[top] + i.second < distance [i.first] ){
                   distance[ i.first] = distance[top] + i.second  ;  
                }

                
            }

}

        }
    }




} ; 
int main (){
    graph<int > g ; 
    g.addEdge(0,1 ,5) ; 
     g.addEdge(0,2,3) ; 
 g.addEdge(1,2,2) ;
  g.addEdge(1,3,6) ;
   g.addEdge(2,3,7) ;
   g.addEdge(2,4,4) ;
   g.addEdge(2,5,2) ;     

   g.addEdge(3,4,-1) ;
   g.addEdge(4,5,-2) ;

   int n = 6 ; // number of nodes in the graph 

   // required things 
   unordered_map<int , bool > visited ; 
   stack<int > s ; 

   for (int i=0 ;i<n;i++){
     if (!visited[i]){
         g.dfs(i, visited , s ) ; 
     }
   }

   // creation of vector distance 
   int src =1 ;
   vector<int > distance(n) ; 
   // making all the values to infinity 

   for ( int i=0 ;i<n ;i++){
    distance[i] = INT_MAX ; 
   }
   


   g.print();  

   // getting the min distance 
   cout<<"The shortest Path is : ";
   g.getShortestPath(src,distance , s)  ;

   // printing the distance map for the order of shortest path 
     for (int i=0 ;i<n ;i++){
        cout<<distance[i]<<"->" ; 
     }
     cout<<endl;
    return 0 ; 
}