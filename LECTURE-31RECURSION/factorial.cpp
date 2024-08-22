#include <bits/stdc++.h>
using namespace std;
// time : O(n) , space : O(n)-> due to recursive stack space 
int factorial(int n)
{
    // base case
    if (n == 0)
        return 1;

    // recursive case
    return n * factorial(n - 1); // recurence relation
}
int main()
{
    int n = 10;
    // cin>> n ;
    // Factorial of a number using recursion
    cout << "The factorial of " << n << " is : " << factorial(n) << endl;
    return 0;
}