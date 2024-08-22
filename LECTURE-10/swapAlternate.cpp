#include <iostream>
using namespace std;
// Program for Swaping the Alterantive indecies elements 
void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[5] = {4, 5, 2, 1, 7};
    print(a, 5);
    for (int i = 0; i < 4; i++)
    {
        swap(a[i], a[i + 1]);
        i++;
    }
    print(a, 5);

    cout << "Swap alternate values in the array " << endl;
    return 0;
}
