#include <bits/stdc++.h>
using namespace std;
// Selection  Sort Algorithm : find the minimum from the right part and check with our current ith value array

// iterative approach
void selectionSortIterative(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // at every ith iteration we are arranging the i-th smallest element to its correct position
        int minIndex = i;
        for (int j = (i + 1); j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

void RecursiveSelectionSort(int *a, int n)
{
    if (n == 0 || n == 1)
        return;
    // work (for 1 case )

    int minIndex = 0; // zeroth index value (har bar array smaller part hi jayega )

    for (int j = 1; j < n; j++)
    { //(0+1 )

        if (a[j] < a[minIndex])
        {
            minIndex = j;
        }
    }
    swap(a[0], a[minIndex]);

    // recursive case
    RecursiveSelectionSort(a + 1, n - 1);
}
void print(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> a = {100, 1, 11, 10, 19, 15, 10};
    int *A = &a[0];
    int n = a.size();

    print(a, n);
    // selectionSortIterative(A, n);
    RecursiveSelectionSort(A, n);
    print(a, n);

    return 0;
}