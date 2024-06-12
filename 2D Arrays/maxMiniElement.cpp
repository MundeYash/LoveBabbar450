#include <bits/stdc++.h>
using namespace std;
// Finding the Maximum and Minimum Element in the 2 D Array

pair<int, int> miniMaxi(int arr[][3], int n, int m)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    // Traversal and Checking Condition (compare )

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > maxi)
            {
                maxi = arr[i][j];
            }

            if (arr[i][j] < mini)
            {
                mini = arr[i][j];
            }
        }
    }
    return {maxi, mini};
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {10, 20, 11}, {50, 0, -1}};
    int n = sizeof(arr) / sizeof(arr[0]);

    int m = sizeof(arr[0]) / sizeof(int);
    pair<int, int> ans = miniMaxi(arr, n, m);

    cout << "The maximum element of the array is : " << ans.first << endl;
    cout << "The Minimum element of the array is : " << ans.second << endl;

    return 0;
}