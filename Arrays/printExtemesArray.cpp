#include <bits/stdc++.h>
using namespace std;
// Printing extrems in the array :means printing the first and last element till they overlap
void printExtremes(int arr[], int n)
{
    // Two pointer technique
    int s = 0, e = n - 1;

    while (s <= e)
    {
        if (s == e)
        {
            cout << arr[s] << " ";
            s++;
            e--;
        }
        else
        {
            cout << arr[s] << "<->" << arr[e] << endl;
            s++;
            e--;
        }
    }

    return;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int n = sizeof(arr) / sizeof(int);
    printExtremes(arr, n);
    return 0;
}
/*
gfg : https://practice.geeksforgeeks.org/problems/print-alternate-elements-of-an-array/1 (done)
*/