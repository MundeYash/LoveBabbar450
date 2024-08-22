#include <bits/stdc++.h>
using namespace std;
// time complexity : O(n) , space : O(n)
void printCounting(int n)
{
    // base case
    if (n == 0)
        return;

    // recursive case
    cout << n << " ";
    printCounting(n - 1); // recurence relation = smaller problem + something
}

void printDecreasingCounting(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // recursive case
    printDecreasingCounting(n - 1); // recurence relation = smaller problem + something
    cout << n << " ";
}
int main()
{
    int n = 10;
    // cin>> n ;
    // Factorial of a number using recursion
    cout << "The Printing of counting in decreasing order is: " << n << " is : " << endl;

    printCounting(n);
    cout << "\nThe Printing of counting in increasing order  is: " << n << " is : " << endl;

    printDecreasingCounting(n);
    return 0;
}