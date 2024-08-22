#include <bits/stdc++.h>
using namespace std;
// Important topic :
// time : O(n log n ) , space : O(n)
void print(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
// function for the merge Sort algorithm : time Complexity : O(log n ) , space : O(n)
// Approach -I *******************
void merge(vector<int> &a, int s, int mid, int e)
{
    int i = s, j = mid + 1;

    // temporary vector for storing ans
    vector<int> temp;
    while (i <= mid and j <= e)
    {
        if (a[i] < a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }

    // if any of the array gets exhausted
    while (i <= mid)
    {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= e)
    {
        temp.push_back(a[j]);
        j++;
    }

    // copy the elements using the indexies
    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i - s];
    }
}

void mergeSort(vector<int> &a, int s, int e)
{
    //              Solved via the use of indexes
    // Step1 : divide the array into two parts till the size becomes equal to the one  (only element left in the array)
    //  base case
    if (s >= e)
        return;
    // two pointers

    int mid = (s + (e - s) / 2);

    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a, s, mid, e);

    // Step 2: Merge the sorted array using the merge function
}

//********************Approach -2

void merge2(int*a, int s, int mid, int e)
{
    // solving via using the extra arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1]; // this is dynamically created arrays
    int *arr2 = new int[len2];

    // elements copy
    int mainArrayIndex = s;

    // first array ke elements copied
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = a[mainArrayIndex++];
    }

    // second array elements copied
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = a[mainArrayIndex];
    }

    // Merge 2 sorted array approach
    // two pointers
    int left = 0, right = 0;

    // temporary vector for storing the answer

    mainArrayIndex = s;
    while (left < len1 and right < len2)
    {
        if (arr1[left] < arr2[right])
        {
            a[mainArrayIndex++] = arr1[left];
            left++;
        }
        else
        {
            a[mainArrayIndex++] = arr2[right];
            right++;
        }
    }

    // if any of the array gets exhausted
    while (left < len1)
    {
        a[mainArrayIndex++] = arr1[left];
        left++;
    }
    while (right < len2)
    {
        a[mainArrayIndex++] = arr2[right];
        right++;
    }

    // after merging delete the dynamic
    delete[] arr1;
    delete[] arr2;
}
void mergeSort2(int*a, int s, int e)
{
    //      solved via the use of extra arrays (Recursion )

    // base case
    if (s >= e)
        return;

    // work
    int mid = (s + (e - s) / 2);

    // divide the array and into two parts recursively apply the mergesort till the array size becomes one
    mergeSort2(a, s, mid);     // s to mid
    mergeSort2(a, mid + 1, e); // mid + 1  to e
    merge2(a, s, mid, e);      // for merging the sorted arrays
}
int main()
{
    vector<int> a = {1, 11, 2, 100, 10, 5};
    int n = a.size();
    print(a, n);
    // mergeSort(a, 0, n - 1);
   int *A = &a[0];
    mergeSort2(A, 0, n - 1);
    print(a, n);

    return 0;
}

// https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/