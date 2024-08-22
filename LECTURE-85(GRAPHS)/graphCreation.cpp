#include<iostream>
#include<unordered_map>// header file for the map 
#include<list>// header file for the list 


using namespace std ;

// this  is lecture no-85 about the graphs 
// creation of graphs 

// using the template for adjusting the data type 
template<typename T >
class graph {
    public : 
    unordered_map<T  ,list<T>  > adj  ; 
    // function for printing the edge 
    void addEdge (T u , T v , bool bidir = true ){
        // bidir = true -> undirected graph 
        // bidir = false -> directed graph 
        adj[u].push_back(v) ; 
        if (bidir ){
            adj[v].push_back(u) ; 
        }
    }
    

    // function for printing the graph 
    void print (){

        for (auto n : adj ){

            cout<<n.first <<"-> (" ; 
            for (auto ch  : n.second ){
                cout<<ch<<", " ;

            }
            cout<<")"<<endl;
        }
    }



} ;
int main ()
{
    // declaration of graph 
    graph <int > g ; 
    // n means number of vertices 
    // m-> means number of edges 


// format for taking the input by the user 

int n ; 
cout<<"Enter the number of nodes/ vertices "<<endl ; 
cin>> n ;
cout<<"Enter the number of edges "<<endl;
int m ; 
cin>> m  ; 
for (int i=0 ;i< m;i++){
    int u , v ; // u-> startig node , v-> ending node 
    cout<<"Enter input for u , v "<<endl;
    cin>> u>> v ; 
    g.addEdge(u,v ) ; 
}
// 5 6 0 1 0 4 1 2 1 3 2 3 3 4 
g.print();

    return 0 ; 
}