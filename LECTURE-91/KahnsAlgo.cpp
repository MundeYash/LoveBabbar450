// This lecture is about printing the topological sort order using the BFS Algo and indegeree concept (KAHN'S)Algorithm 

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std ; 
template<typename T> 
// creation of class 
class graph{
 public : 
 // creation of ajacency list 
 unordered_map< T , list<T>> adj ; 

 // function for adding edge 
 void addEdge(T u , T v , bool bidir = false ){
    adj[u].push_back(v) ; 
    if (bidir ){
        adj[v].push_back(u);
    }
 }
 // function for printing adjacency list 
  void print (){
 for (auto n : adj ){
    cout<<n.first<<"->(" ; 
    for (auto ch :n.second){
        cout<<ch<<",";
    }
    cout<<")"<<endl;
 }
  }
  // function for finding the topological order from BFS(KAHN's) Algo 
 vector <int >  kahnsAlgo( ){
    // creation of queue 
    queue<T > q ; 
    vector<T > ans  ; 
   
    // indegree ka vector 
    vector<T> indegeree  ; 

    // Step1 find all the indegrees 
    for (auto i : adj ){
        for (auto j : i.second){
            indegeree[j]++ ;
        }

    }
    // step2 0 indegree walo ko queue mein push kardo 
    for (auto n: adj){
        for (auto i: n.first){
            if (indegeree[i] == 0){
                q.push(i);
            }
        }
    }

    // work for bfs 
     while(!q.empty()){
        int front = q.front() ; 
        q.pop( ) ; 
        ans.push_back(front);
         for (auto ch :adj[front] )
         {
            indegeree[ch] -- ; 
            if (indegeree[ch] == 0 ){
                q.push(ch);
            }
         }
        
     }
      return ans ; 
      
   }
    
} ;
int main (){
     cout<<"Work";
     graph<int >  g; 
     vector<int> ans ; 
    
     g.addEdge(1,2) ; 
     g.addEdge(1,3) ; 
     g.addEdge(2,5) ; 
    g.addEdge(3,5) ;
    g.addEdge(5,4) ;  
    // vector<int > ans (6);
    g.print();
      ans =  g.kahnsAlgo();
      for (auto i= ans.begin() ; i != ans.end() ; i ++ ){
        cout<< *i<<" ";
      }
    

    
    return 0  ; 
}