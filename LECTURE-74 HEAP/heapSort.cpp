#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if (leftChild <= n and arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild <= n and arr[rightChild] > arr[largest])
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

// function for sorting any given array using the heap sort algorithm (Olog n ) time ;
void heapSort(int arr[], int n)
{// time : O(n log n )
    // step 1 : building the heap 

    // step 1: place  the last element with the first element
    int size = n;
    while (size > 1)
    {

        swap(arr[1], arr[size]);
        size--;

        heapify(arr, n, 1);
    }
}

int main()
{
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(int);
    n--; // for the garbage index value

    cout << "Heapify : " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "Heapify sort  : " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
https://leetcode.com/problems/sort-an-array/description/

https://practice.geeksforgeeks.org/problems/heap-sort/1   (rem)
*/