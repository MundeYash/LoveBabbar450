#include <bits/stdc++.h>
using namespace std;
// Question 1:sort the 012 without sorting

void sort012(vector<int> &arr, int n)
{

    // most optimised approach

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {

            mid++;
        }

        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    return;
}

void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> arr = {0, 1, 2, 2, 2, 1, 1, 0, 0, 1, 1, 0, 2};
    int n = arr.size();
    int k = 3;
    printArray(arr, n);
    sort012(arr, n);
    printArray(arr, n);

    return 0;
}