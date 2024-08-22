#include <bits/stdc++.h>
using namespace std;

// Rat in Maze problem : given an maze of N*M size containing 0 and 1 and a mouse who can move from (0,0) source to destinatino (n-1 , m-1) and only allowed to move in up , down , left and right direction to cell having 1
//  We need to return all the possible path from source to destination
// timecomplexity : O(4 * (M*N) ) , space complexity : o(4 * (n*n))
bool isSafe(vector<vector<int>> matrix, vector<vector<int>> visited, int n, int x, int y) 
{
    // if the coordinate is in range
    if ((x >= 0 and x <= n - 1) and (y >= 0 and y <= n - 1) and (visited[x][y] == 0) and (matrix[x][y] == 1))
    {
        return true;
    }
    return false;
}
void solve(vector<vector<int>> matrix, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path , int di[] , int dj[])
{
    // you have reached x , y 
    // base case
    if (x == n - 1 and y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // recursive case
  

    // (Instead of checking for all four condition seperately we use it via an array to corresponding generating the coordiantes )

    // choices =4 (up , down , left , right )
    string dir = "DLRU";
    for (int index = 0 ; index <4 ; index++){
        int newX = x + di[index]    ;
        int newY = y + dj[index];
        if(isSafe(matrix , visited , n , newX , newY )){
              visited[x][y] = 1;

              solve(matrix , n , ans , newX , newY  ,visited,path+dir[index] , di , dj ) ;
               visited[x][y] = 0; // marking it again as unvisited for backtracking


        }
    }

   
   
}
vector<string> ratInMaze(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<string> ans;

    if (matrix[0][0] == 0)
    {
        return ans; // means our source is 0
    }

    int srcX = 0;
    int srcY = 0;

    // visited array for update
    vector<vector<int>> visited (n , vector<int> (n,0)); // marking all the cells intially unvisited
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         visited[i][j] = 0;
    //     }
    // }
    string path = "";
    int di [] = {+1, 0,0,-1  }; //down , left  , right , up 
    int dj [] = {0 , -1, 1 , 0 }; // down , left  , right , up

    solve(matrix, n, ans, srcX, srcY, visited, path , di  , dj );
    sort(ans.begin(), ans.end()); // for lexographically sorted answers
    return ans;
}
// for printing matrix
void printMatrix(vector<vector<int>> m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

// for printing path
void printAns(vector<string> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{

    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    int n = matrix.size();
    // printMatrix(matrix);
    vector<string> ans = ratInMaze(matrix);
    printAns(ans);
    return 0;
}
/*
https://www.codingninjas.com/studio/problems/rat-in-a-maze_1215030?leftPanelTab=0 (rem)
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1 (done)
*/