#include <iostream>
using namespace std;
// time : O(N) , space  :O(n) - > recursive stack space 
bool checkSorted(int a[], int n)
{
    if (n == 0 || n == 1)
        return true;

    if (a[0] > a[1])
        return false;

    else
    {

        return checkSorted(a + 1, n - 1);
    }
}
int main()
{
    int a[] = {0, 1, 3, 11, 11, 100};
    int n = sizeof(a) / sizeof(int);
    cout << "The array is sorted or not : " << checkSorted(a, n) << endl;
}