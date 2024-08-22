// Function for finding the valid topological sort 
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
  // helper function 
  void help (int node , unordered_map<int , bool > & visited , stack <int> &s ){
    visited[node] = true ; 
    for (auto ch : adj [node]){
        if (!visited[ch]){
            help(ch , visited , s  ) ; 
        }
    }
    s.push(node) ; 

  }

  // function for printing the valid topological sort 
void  topLogic (vector<int > &ans   ){
    
    stack <int > s ; 
    unordered_map<int  , bool > visited ;
    for (auto n : adj ){
        help(n.first , visited , s  ) ; 


    }
    while (!s.empty ()){
        ans.push_back(s.top()) ; 
        s.pop() ; 
    }
     
  }

    
} ;
int main (){
     graph<int >  g; 
    g.addEdge(0,1); 
     g.addEdge(0,3); 

      g.addEdge(2,1);
        //    g.addEdge(4,5);
    //             g.addEdge(5,6);
    //  g.addEdge(6,4);
       g.addEdge(3,2);

       //printing the list 
       g.print( ) ;
        vector <int > ans ; 
        g.topLogic(ans);
       
        
for (int i=0;i<4 ;i++){
    cout<<ans[i]<<" ";
}  
cout<<endl;
    return 0  ; 
}