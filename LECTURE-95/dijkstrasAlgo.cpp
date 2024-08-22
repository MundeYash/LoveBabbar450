#include<bits/stdc++.h>
using namespace std ; 
// this is CODE for finding the minimum distance of source node form all the nodes using the (DIJKSTRA'S) ALGORITHM 

// creation of class graph 
template<typename T  > 
class graph{
    public : 

    unordered_map<T , list<pair <T , T >> > adj ; 

    // function for adding the edge 
    void addEdge(T u  ,T v , T w ){

        adj[u].push_back(make_pair (v,w)) ; 
        adj[v].push_back(make_pair(u,w))   ; 
    }

// function for finding the shortest distance of source node from all nodes 
 vector<int > dijkstras(int src  , int n ){
    // needes things 
     set<pair <T ,T > > s  ; 
    vector < T >  dis (n ) ; 
    // setting all the values to infinity 
    for (int i=0 ;i<n ;i++){
        dis[i] = INT_MAX; 
    }
    dis[src] = 0  ; 
    s.insert(make_pair (dis[src] , src)) ; 

    while(!s.empty()){
        auto top = *(s.begin()) ; 

        T    topDistance = top.first ; 
        T    topNode = top.second ; 

        s.erase(s.begin()) ; 

        for (auto ch : adj [topNode]){

            if (topDistance + ch.second < dis[ch.first ]){


                // find the already existing record and if found delete it 
                auto record = s.find( make_pair(dis[ch.first ] , ch.first )) ; 
                if (record != s.end()){
                    s.erase(record) ; 

                }

                // than updating the distance 
                dis[ch.first] = topDistance + ch.second ; 

                s.insert(make_pair(dis[ch.first] , ch.first) ) ; 

            }
        }
    }

   return dis ; 

 }
 // function for printing the edge 
 void print (){
    for (auto n : adj){
        cout<<n.first <<":->";
        for (auto ch : n.second ){
            cout<<"("<<ch.first<<","<<ch.second<<")"; 
        }
        cout<<endl;
    }
 }
} ; 

int main ()
{
    graph<int > g ; 
    g.addEdge(0,1 , 5);
     g.addEdge(0,2,8);

      g.addEdge(1,2,9);
     g.addEdge(1,3,2);

     g.addEdge(2,3,6);
     int n = 4 ; 
     g.print () ; 
     vector <int > ans ; 
     int src =0 ; 
    ans = g.dijkstras(src, n) ;
    cout<<endl<<"The ans is :"<<endl; 
     for (int i=0 ;i<n ;i++){
        cout<<src<<"->"<<i<<" ="<<ans[i]<<endl ;
     }
    return 0 ;  
}