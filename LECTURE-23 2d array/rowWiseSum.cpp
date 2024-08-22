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


// function for finding the row-wise sum in a matrix
vector<int> rowWiseSum(vector<vector<int>> matrix)
{
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += matrix[i][j];
        }
        ans.push_back(sum);
    }
    return ans;
}

// function for finding the col-wise sum in a matrix
vector<int> colWiseSum(vector<vector<int>> matrix)
{
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += matrix[i][j];
        }
        ans.push_back(sum);
    }
    return ans;
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
    vector<int> ans = rowWiseSum(arr);
    vector<int> ans1 = colWiseSum(arr);
    print(ans);
    print(ans1);

    return 0;
}
