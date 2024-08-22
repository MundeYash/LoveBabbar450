#include <bits/stdc++.h>
using namespace std;

void reverseArray(int a[], int n)
{
    int s = 0, e = n - 1;

    while (s < e)
    {
        swap(a[s], a[e]);
        s++;
        e--;
    }
    return;
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
    reverseArray(a, n);

    cout << "After reversing " << endl;
    output(a, n);
    delete[] a;




    /*
            code studio : https://www.codingninjas.com/studio/problems/reverse-the-array_1262298?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker (done)
            gfg : 

    */
}