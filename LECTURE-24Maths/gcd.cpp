#include <bits/stdc++.h>
using namespace std;
// Greatest common divisor (highest common factor ):Solving using the Eucledian algorithm

int gcd(int a, int b)
{
    // Iterative code
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a != b)
    {

        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int gcdRecursive(int A, int B)
{
    // Approach : Eucledian Algorithm
    while (A > 0 and B > 0)
    {
        if (A > B)
        {
            A = A % B;
        }
        else
        {
            B = B % A;
        }
    }
    if (A == 0)
    {
        return B;
    }
    else
    {
        return A;
    }
    return -1;
}
// function for printing
void print(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a, b;
    cin >> a >> b;



    // cout << "The gcd of a and b is :" << gcd(a, b) << endl;
    // cout << "The gcd of a and b is :" << gcdRecursive(a, b) << endl;

    return 0;
}

/*Similiar Quesiton practice links



*/