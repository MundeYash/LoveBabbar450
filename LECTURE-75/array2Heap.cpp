// Question : given an array and we need to conver the given array to the max -heap using the (heapify algorithm )

#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int i, int n)
{
    int largest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if (leftchild < n and arr[leftchild] > arr[largest])
    {
        largest = leftchild;
    }
    if (rightchild < n and arr[rightchild] > arr[largest])
    {
        largest = rightchild;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}
vector<int> array2Heap(vector<int> arr, int n)
{

    // step 1 : apply the heapify algorithm
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
    return arr;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 19, 10};
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    vector<int> ans = array2Heap(arr, n);

    // printing the array and checking if it's heap

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
/*
gfg question : https://practice.geeksforgeeks.org/explore?page=1&category[]=Heap&category[]=priority-queue&sortBy=submissions

*/