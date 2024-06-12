#include <bits/stdc++.h>
using namespace std;
// Find the Transpose of the Matrix : Means internchange the position of rows and columns

void Transpose(int arr[3][3], int n, int m, int transposeArr[3][3])
{
    // Concept : using an Extra array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            transposeArr[i][j] = arr[j][i];
        }
    }
}

// Function for printing the array
void printArray(int arr[3][3], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int transposeArr[3][3];

    int n = 3, m = 3;
    cout << "Before Transpose " << endl;
    printArray(arr, n, m);

    Transpose(arr, n, m, transposeArr);

    cout << "After Transpose " << endl;

    printArray(transposeArr, n, m);

    return 0;
}