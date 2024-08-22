#include<bits/stdc++.h>
using namespace std ; 


// function for heapify algorithm for the max -heap creation 
// function for heapify alogrithm
void heapify(int arr[], int n, int i)
{

    // time complexity : O(n) 
// assumption is 1 based indexing 
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if (leftChild < n and arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild < n and arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);

        // work for the other possible options

        heapify(arr, n, largest);
    }
}
int main (){

     // heapify function implementation

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(int);

    // to not include 0th index
    n = n - 1;

    // n to n /2 index range are already heapified for the max- heap (leaf nodes )

    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }

    // for checking whether the changes are reflected or not

    cout << "Heapify : " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;



    return 0 ;
}