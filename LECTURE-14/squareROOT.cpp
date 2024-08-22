#include <iostream>
using namespace std;
// function for adding more precision in the square root ans
double morePrecision(int n, int precision, int tempSol)
{
    double ans = tempSol;
    double factor = 1;

    for (int i = 1; i <= precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j <= n; j = j + factor)
        {
            ans = j; // ans ko store karalo and more precison ke liye check karo
        }
    }
    return ans;
}

// function for finding the square root of a number
int squreRoot(int n)
{
    int s = 0, e = n;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        long long int sqr = mid * mid;
        if (sqr == n)
        {
            return mid;
        }
        else if (sqr < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;

    cout << "The floor value of square root is : " << squreRoot(n) << endl;
    int tempAns = squreRoot(n);
    cout << "More Precised answer of square root " << morePrecision(n, 6, tempAns) << endl;

    return 0;
}