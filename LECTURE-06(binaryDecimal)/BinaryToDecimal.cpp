#include <bits/stdc++.h>
using namespace std;

// Binary Number Representation to Decimal Number Form Conversion

int main()
{
    int n, ld = 0, ans = 0, i = 0;
    cin >> n; // give the binary input in form of 0s and 1s which is actual an integer 
    while (n != 0)
    { // last digit concept using the modulo operator
        ld = n % 10;
        ans = ld * (pow(2, i)) + ans; // Main Formula
        i++;
        // update the number
        n = n / 10;
    }
    cout << ans << endl;
    cout << "Binary to Decimal Conversion " << endl;
    return 0;
}