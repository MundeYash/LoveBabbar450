#include <bits/stdc++.h>
using namespace std;
// This is lecture is about the introduction to the arrays

// what is the use of memset function in c++
int main()
{

    const int size = 5;
    int myArray[size];

    // Initialize the entire array with the value 42
    memset(myArray, 42, size * sizeof(int));

    // Print the array
    for (int i = 0; i < size; ++i)
    {
        std::cout << myArray[i] << " ";
    }
    int arr[10];

    cout << ":)" << endl;
    memset(arr, 2, sizeof(arr));

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "t" << endl;
    return 0;
}