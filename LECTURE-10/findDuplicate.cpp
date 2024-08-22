#include <iostream>
using namespace std; // constraints are elements must be duplicate and ranging from 1 to size -1 like (if n=5 1-4)
int find_duplicate(int a[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i]; // concept :- XOR operation
    }
    for (int i = 1; i < n; i++)
    {
        ans = ans ^ i;
    }

    return ans;
}
int main()
{
    int a[] = {
        5,
        5,
        1,
        2,
        3,
        4,
    };
    int n = sizeof(a) / sizeof(int);
    cout << "The Duplicate element present in the array is :" << find_duplicate(a, n) << endl;
    cout << "This lecture is about finding duplicate in the array \n";
    return 0;
}