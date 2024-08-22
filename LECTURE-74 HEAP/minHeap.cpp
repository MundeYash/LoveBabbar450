#include<bits/stdc++.h>
using namespace std ; 


// function for heapify algorithm for the min  -heap creation 
// function for heapify alogrithm
void heapify(int arr[], int n, int i)
{

    // time complexity : O(n) 
// assumption is 1 based indexing 
    int smallest  = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if (leftChild <= n and arr[leftChild] < arr[smallest])
    {
        smallest = leftChild;
    }

    if (rightChild <= n and arr[rightChild] < arr[smallest])
    {
        smallest = rightChild;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);

        // work for the other possible options

        heapify(arr, n, smallest);
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


// https://www.codingninjas.com/studio/problems/build-min-heap_1171167?leftPanelTab=0  (done)
// https://www.codingninjas.com/studio/problems/min-heap-implementation_5480527?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0 (rem )