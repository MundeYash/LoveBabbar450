// this is the code of problem in code studio 

// #include <bits/stdc++.h> 

// #include<unordered_map>
// #include<vector>
// #include<set> // header file for the set ( because to get the sorted order )
// // doc = 06 jan 23 

// // function for input of adjacency list 
// void prePareadj(unordered_map<int , set<int>> &adj , vector<pair<int, int>> &edges){
    
//     // iterating over the edges 
//     for (int i=0 ;i<edges.size() ; i++){
        
//         int u = edges[i].first ; 
//         int v = edges[i].second ; 
        
//         adj[u].insert(v) ; 
//         adj[v].insert(u) ; 
//     }
// }

// // valuable function our for problem 
// void bfs (  unordered_map<int , set<int>> &adj ,unordered_map<int, bool > &visited ,vector <int > &ans , int src     ){
//     // creation of queue 
//     queue<int> q; 
//     q.push(src ) ; 
//     visited[src] = true ; 
    
//     while (!q.empty()){
//         int father  = q.front() ; 
//         q.pop() ; 
        
//         // instead of printing we need to store the ans in vector 
//         ans.push_back(father );
//         // iterating over the childs of father 
//         for (auto ch : adj[father ]){
            
//             if (!visited[ch]){
//                 q.push(ch) ; 
//                 visited[ch] = true ; 
                
//             }
//         }
//     }
    
// }

// vector<int> BFS(int vertex, vector<pair<int, int>> edges)
// {
//     // creation of map for adjacency list and visited 
//     unordered_map<int , set<int>> adj ; 
//     unordered_map<int, bool > visited ; 
//     // creation of vector for ans storing 
//     vector <int > ans  ; 
    
//     // for getting the input in the adjacency list make a function 
//     prePareadj(adj , edges )  ; 
    
//     // for iterating over all the vertexes 
//     for (int i=0 ;i<vertex ;i++){
//         if (!visited[i]){
//             // call our Bfs function (valuable function for the code )
//             bfs(adj , visited ,ans  , i ) ; 
            
//         }
//     }
//      return ans  ; 
    
    
// }
// int main (){
//     return 0  ;
// }