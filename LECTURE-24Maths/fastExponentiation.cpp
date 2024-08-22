#include <bits/stdc++.h>
using namespace std;
// FAst exponentiation (modular exponentiation )

int modularExponentiation(int x, int n, int M)
//((x^n)%m)
{
    // Approach :Modular exponenetiation (to keep our answer in the range )
    // if power is even
    int ans = 1;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            // half the power and square the number
            x = (long long)((x) * (x)) % M;
            n = n >> 1; // n/2
        }
        else
        {
            // power is odd
            ans = (long long)(ans * (x)) % M;
            n = n - 1;
        }
    }
    return (int)ans;
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
    int a = 4, b = 3, m = 10;
    int ans = modularExponentiation(a, b, m);
    cout << "The answer will be :" << ans << endl;

    int mod = 10e7;

    return 0;
}

/*Similiar Quesiton practice links

https://leetcode.com/problems/super-pow/description/
https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1




*/