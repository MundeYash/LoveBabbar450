
#include <bits/stdc++.h>
using namespace std;
// given two heaps in the form of the vector and we need to merge these two heaps form a new heap

void heapify(vector<int> &arr, int n, int index)
{
    int largest = index;
    int leftchild = (2 * index) + 1;
    int rightchild = (2 * index) + 2;

    if (leftchild < n and arr[leftchild] > arr[largest])
    {
        largest = leftchild;
    }

    if (rightchild < n and arr[rightchild] > arr[largest])
    {
        largest = rightchild;
    }

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }

    return;
}
void array2Heap(vector<int> &arr, int n)
{

    for (int i = (n / 2) - 1; i >= 0; i--)
    { // taking the 0 based indexing
        heapify(arr, n, i);
    }

    return;
}
vector<int> merge2Heaps(vector<int> &a, int n, vector<int> b, int m)
{
    // step 1 : merge both the given arrays to form a single array
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(a[i]);
    }

    for (int j = 0; j < m; j++)
    {
        ans.push_back(b[j]);
    }

    // step2 : apply the heapify algo to conver the array to heap
    int N = ans.size();
    for (int i = (N/ 2) - 1; i >= 0; i--)
    {
        heapify(ans, N, i);
    }
}

void print(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr1 = {10, 5, 6, 2};
    int n1 = arr1.size();

    print(arr1, n1);

    vector<int> arr2 = {12, 7, 9};
    int n2 = arr2.size();
    print(arr2, n2);

    vector<int> ans = merge2Heaps(arr1, n1, arr2, n2);
    print(ans, ans.size());
    return 0;
}
// date to code : 15 oct 23

/*
code studio ;  https://www.codingninjas.com/studio/problems/merge-two-binary-max-heaps_1170049  (done )
leetcode :
gfg : https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1  (done )
interview bit :

*/