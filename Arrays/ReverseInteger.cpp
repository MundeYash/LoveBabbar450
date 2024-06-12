// date -06 December 2023 (Reverse the given integer )
#include <bits/stdc++.h>
using namespace std;

// Given an integer and give the reverse of the integer. If the given integer is greater than INT_MAX and smaller than the INT_MIN . In both the cases return 0 ;

int reverseInteger(int n)
{
    bool isNegative = false;
    if (n < 0)
    {
        isNegative = true;
        if (n < INT_MIN)
        {
            return 0;
        }

        n = -n;// convert the positive 
    }

    if (n > INT_MAX)
        return 0;

    int ans = 0;

    while (n > 0)
    {
        int ld = n % 10;

        if (ans < INT_MIN / 10 || ans > INT_MAX / 10)// to ensure that the value should be in range 
            return 0;

            
        ans = (ans * 10) + ld;

        n = n / 10;
    }

    if (isNegative)
        return (-ans);

    return ans;
}
int main()
{
    int n;
    cin >> n;

    cout << "The given integer is " << n << endl;
    cout << "The reverse of integer is : " << reverseInteger(n) << endl;

    return 0;
}

/*
Reverse Integer

Leetcode : https://leetcode.com/problems/reverse-integer/  (done)
codestudio :
gfg :
interview bit :


*/