#include <bits/stdc++.h>
using namespace std;
// find The ways to reach the nth Stair from source to destination (condition you can either jump to one above staircase or two above staircase )
// time  : O(log n ) ,space : O(log n )
void sayDigits(int n, string a[10])
{
    // base case
    if (n == 0)
        return;

    int digit = n % 10;
    n = n / 10;

    sayDigits(n, a);
    cout << a[digit] << " ";
}

int main()
{
    int n = 5;
    cin >> n;

    string a[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << a[4] << endl;
    sayDigits(n, a);

    return 0;
}