#include <bits/stdc++.h>
using namespace std;
// Question 1: find the Kth Maximum and Kth minimum element in the array

pair<int, int> miniMaxi(vector<int> &arr, int n, int k )
{
    // sort the array: using the Sorting  
    sort(arr.begin() , arr.end()) ; 

    return {arr[n-k] , arr[k-1]};

    
}
int main()
{

    vector<int> arr = {2, 4, 1, 11, 1001, 31,101};
    int n = arr.size();
    int k = 3 ; 
    pair<int, int> ans = miniMaxi(arr, n, k);

    cout << "The minimum element of the array is :" << ans.second << endl;
    cout << "The maximum element of the array is :" << ans.first << endl;

    return 0;
}