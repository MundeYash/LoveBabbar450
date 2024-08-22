#include <iostream>
using namespace std;
// Array sum -> recursive => time : O(n) , space : O(n)
int arraySum(int a[], int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
    {
        return a[0];
    }

    int sum = a[0] + arraySum(a + 1, n - 1);

    return sum;
}
int main()
{
    int a[] = {0, 1, 3, 11, 11, 100, 1000};
    int n = sizeof(a) / sizeof(int);
    cout << "The array sum is  : " << arraySum(a, n) << endl;
}