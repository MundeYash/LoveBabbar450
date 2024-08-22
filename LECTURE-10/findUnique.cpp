#include <iostream>
using namespace std;

// finding the unique element in the array

// Approach 1 : Count Method

int find_Unique2(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int value = a[i];

        for (int j = 0; j < n; j++)
        {
            if (a[j] == value)
            {
                count++;
            }
        }
        if (count == 1)
        {
            return value;
        }
    }
    return -1;
}

// Approach 2 : Using XOR Operation
int find_Unique(int a[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i]; // concept : (Use of XOR operation )
    }
    return ans;
}

int main()
{
    int a[] = {1, 3, 3, 1, 4, 4, 11, 5, 5};
    int n = sizeof(a) / sizeof(int);
    cout << "The answer from 1st Method : " << find_Unique2(a, n) << endl;
    cout << "the Solution  from 2nd Method is :  " << find_Unique(a, n) << endl;

    cout << "Finding Unique element in the Array \n";
    return 0;
}