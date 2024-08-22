#include <bits/stdc++.h>
using namespace std;

// Decimal number to Binary conversion
int main()
{
    int n, ld = 0, ans = 0; // a decimal number in input
    cin >> n;
    int copy =n;
    int i = 0;
    while (n != 0)
    {
        ld = (n & 1);

        ans = ld * (pow(10, i)) + ans; // Main FORMULA used

        // update the number
        n = n >> 1;
        i++;
    }
    cout << "The binary representation of " << copy << " is: " << ans << endl;
    cout << "Decimal to Binary Conversion " << endl;

    return 0;
}