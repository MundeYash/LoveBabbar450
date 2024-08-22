#include <iostream>
using namespace std;
void reverseString(string &a, int s, int e)
{
    // base CAse
    if (s > e)
        return;

    swap(a[s], a[e]);
    reverseString(a, s + 1, e - 1);
}
void reverseString2(string &a, int i, int n)
{

    // base CAse
    if (i == n)
        return;

    swap(a[i], a[n - i - 1]);
    reverseString2(a, i++, n);
}
// OUTPUT Print
void print(string &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    string a = "palindrome";
    // int n = sizeof(a) / sizeof(int);
    int n = a.size();
    print(a, n);
    // reverseString(a, 0, n - 1);
    reverseString2(a, 0, n);
    print(a, n);
}