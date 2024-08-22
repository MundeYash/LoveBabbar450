// Cycle Detection in directed graph 

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

    // function for detecting cycle in directed graph 
    bool isCyclic(T node , unordered_map<T , bool > &visited , 
        unordered_map<T, bool >&dfsVisited){
            // work for source 
            visited[node] = true ; 
            dfsVisited[node] = true ; 

            // call for the childs 
            for (auto ch  : adj[node]){
                if (!visited[ch]){
                    bool ans = isCyclic(ch , visited , dfsVisited ) ; 
                    if (ans == true ){
                        return true ; 
                    }
                }
                else if (dfsVisited[ch] == true and visited[ch] == true ){ // this is main condition of cycle detection 
                return true ; 

                }
            }
             dfsVisited[node] = false ; 
             return false ;

    }

    // help dfs function 
    bool helpDfs( ){
        unordered_map<T , bool > visited ; 
        unordered_map<T, bool >dfsVisited  ; 
        // for iterating over all the components of graph 
        for (auto n : adj ){
            // calling our call isCyclic 
            bool ans = isCyclic (n.first , visited , dfsVisited ) ; 
            if (ans ){
                return true  ; 
            }
        
        }
         return false  ; 
    }
 

} ;
int main (){
     graph<int >  g; 
    g.addEdge(1,0); 
     g.addEdge(0,3); 

      g.addEdge(2,1);
        //    g.addEdge(4,5);
    //             g.addEdge(5,6);
    //  g.addEdge(6,4);
       g.addEdge(3,2);

       //printing the list 
       g.print( ) ;
       if (g.helpDfs()){
        cout<<"Present"<<endl;

       }
       else {
        cout<<"Not Present " ;
       }

    return 0  ; 
}