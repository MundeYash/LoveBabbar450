// CONCEPT : TWo POINTERS
#include <iostream>
using namespace std;

// Moving all the zeroes in the array to the right side
void moveZeroes(int a[], int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] != 0)
        {
            // shifting all the non zeroes to left side 
            swap(a[i], a[j]);
            i++;
        }
    }
}

// output function for array printing
void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
// input  function for taking input
void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int main()
{//5 0 1 0 3  12
    int n;
    cin >> n;
    int *a = new int[n];
    input(a, n);

    output(a, n);
    moveZeroes(a, n);
    cout << "The output after moving all the zeroes to right :";
    output(a, n);

    return 0;
}