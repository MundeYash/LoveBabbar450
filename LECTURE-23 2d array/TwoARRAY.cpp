// Creation of 2D array

#include <iostream>
using namespace std;

// function for taking the input of the 2 d array
void TwodArrayINput(int a[][2], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{

    // declaration of 2d array (datatype arrayname[noOfRows ][noOfColumns])

    int arr[4][2];

    // taking of input of 2 D array from the user
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    // declaration of 2d array

    TwodArrayINput(arr, 4, 2);

    return 0;
}