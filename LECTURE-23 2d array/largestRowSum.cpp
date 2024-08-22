#include <bits/stdc++.h>
using namespace std;

// RoW wise sum of a matrix

void output(int a[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void input(int a[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
}

// function for finding the largest  row-wise sum in a matrix
int rowWiseSum(vector<vector<int>> matrix)
{
    int largest = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += matrix[i][j];
        }
        largest = max(largest, sum);
    }
    return largest;
}

// function for finding thelargest  col-wise sum in a matrix
int colWiseSum(vector<vector<int>> matrix)
{
    int largest = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();
    
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += matrix[i][j];
        }
         largest = max(largest, sum);
    }
    return largest;
}
void print(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{

    // declaration of 2d array (datatype arrayname[noOfRows ][noOfColumns])

    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3, m = 3;
    cout << "The largest row sum is :" << rowWiseSum(arr) << endl;
    cout << "The largest col sum is :" << colWiseSum(arr) << endl;

    return 0;
}
