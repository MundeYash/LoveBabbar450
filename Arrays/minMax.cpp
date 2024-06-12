#include <bits/stdc++.h>
using namespace std;
// Question 1: find the minimum and maximum element in the array

pair<int, int> miniMaxi(vector<int> arr, int n)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mini)
        {
            mini = arr[i];
        }

        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return {maxi, mini};
}
int main()
{

    vector<int> arr = {2, 4, 1, 11, 1001};
    int n = arr.size();
    pair<int, int> ans = miniMaxi(arr, n);

    cout << "The minimum element of the array is :" << ans.second << endl;
    cout << "The maximum element of the array is :" << ans.first << endl;

    return 0;
}