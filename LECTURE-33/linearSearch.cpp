#include <iostream>
using namespace std;
// linear search -> recursive => time : O(n) , space : O(n)
int linearSearch(int a[], int n, int key)
{
    if (n == 0)
        return -1;

    if (a[n - 1] == key)
    {
        return n - 1;
    }

    return linearSearch(a, n - 1, key);
}
int main()
{
    int a[] = {0, 1, 3, 11, 11, 100, 1000};
    int n = sizeof(a) / sizeof(int);
    cout << "The array sum is  : " << linearSearch(a, n, 11) << endl;
}