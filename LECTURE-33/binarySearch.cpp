#include <iostream>
using namespace std;
// time : O(Log n  ) , space : O(log n ) - > recursive stack space (log n times function call )
int binarySearch(int a[], int s, int e, int key)
{
    // base case
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;
    if (a[mid] == key)
        return mid;

    else if (a[mid] > key)
    {
        return binarySearch(a, s, mid - 1, key);
    }
    else
    {
        return binarySearch(a, mid + 1, e, key);
    }
}
int main()
{
    int a[] = {0, 1, 3, 11, 11, 100, 1000};
    int n = sizeof(a) / sizeof(int);
    cout << "The array sum is  : " << binarySearch(a, 0, n - 1, 1000) << endl;
}