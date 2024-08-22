#include <bits/stdc++.h>
using namespace std;
int linearSearch(int a[], int n, int key)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    input(a, n);
    output(a, n);
    cout << "The key is present at index :" << linearSearch(a, n, 3) << endl;
}