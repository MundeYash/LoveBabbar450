#include <bits/stdc++.h>
using namespace std;

// Searching an element in the 2D array
pair<int, int> LinearSearch2d(int arr[][3], int n, int m, int key)
{

    // search element while traversing the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == key)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// function for printing the array

void printArray(int arr[][3], int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr[0]) / sizeof(int);
    cout << n << endl
         << m << endl;

    printArray(arr, n, m);
    int key = -8;
    pair<int, int> ans = LinearSearch2d(arr, n, m, key);
    if (ans.first==-1 ){
        cout<<"Key Not Present "<<endl;
    }
    else{
        cout << "Searching " << key << " Row no:" << ans.first << ",column no :" << ans.second << endl;

    }

    return 0;
}