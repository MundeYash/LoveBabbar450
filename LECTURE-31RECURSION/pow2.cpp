#include <bits/stdc++.h>
using namespace std;
// time  complexity  : O(n) , space ; O(n)
int pow2(int n)
{
    // base case
    if (n == 0)
        return 1;

    // recursive case
    return 2 * pow2(n - 1); // recurence relation
}
int main()
{
    int n = 11;
    // cin>> n ;
    // Caclcute the of a number using recursion
    cout << "The power  of " << n << " is : " << pow2(n) << endl;
    return 0;
}