#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 10;
    // // Printing the counting form 1 to n
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " ";
    // }
    // cout << "counting Printed " << endl;

    // finding the Sum of a number from 1 to n
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "The sum of " << n << " numbers is : " << sum << endl;
    return 0;
}