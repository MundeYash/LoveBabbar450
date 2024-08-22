#include <bits/stdc++.h>
using namespace std;
//Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.
// time complexity for the worst Case is  : O(n^2)
// features : in-place algorithm does uses extra array , but not a stable algorithm as the relation order of element gets changed many times 
void print(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int partition(int *a, int s, int e)   
{
    int pivot = a[s]; // assume the starting index of array to be pivot

    // step2 : Find all the elements smaller than pivot
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (a[i] <= pivot)
        {
            count++;
        }
    }
    // place the pivot at right position
    int pivotIndex = s + count;
    swap(a[pivotIndex], a[s]);

    // Sort the left part and sort the right part
    int left = s, right = e;

    while (left < pivotIndex and right > pivotIndex)
    {
        while (a[left] <= pivot)
        {
            left++;
        }
        while (a[right] > pivot)
        {
            right--;
        }

        // main case (this is the case where : a[left]> pivot and a[right]<pivot )
        if (left < pivotIndex and right > pivotIndex)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }

    return pivotIndex;
}
// function for the Quick Sort algorithm : time Complexity :Average case :  O(log n ) , space : O(n)
void quickSort(int *a, int s, int e)
{
    // base case
    if (s >= e)
        return; // means already sorted

    // work
    // find the partion index and sort for left part and right part
    int p = partition(a, s, e);

    // recursive case

    // left part sort karege
    quickSort(a, s, p - 1);

    // right part sort karenge
    quickSort(a, p + 1, e);
}
int main()
{
    vector<int> a = {6, 6, -6, -2 ,-4 ,-6, 2, -6};
    int n = a.size();
    print(a, n);
    // mergeSort(a, 0, n - 1);
    int *A = &a[0];
    quickSort(A, 0, n - 1);

    print(a, n);

    return 0;
}

// related questions : Why quick sort is preffered over the merge sort for sorting an arrays ? q2 -> Why merge  sort is preffered over the quick  sort for sorting link lists ? 
// https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/