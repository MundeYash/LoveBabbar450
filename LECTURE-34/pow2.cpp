#include <bits/stdc++.h>
using namespace std;
// time : O(log base b (n)) , space : (log (base b of (n)))
int powerA2B(int a, int b)
{
    // Base case
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    // work
    int ans = powerA2B(a, b / 2);

    if (b %2 ==0 )
    {
        // Even power
        return ans * ans;
    }
    else
    {
        // odd Power
        return a * (ans * ans);
    }
}
// Finding the Power of a to the b (using the recursion )
int main()
{
    int a = 2, b = 10;
    // cin >> a >> b;
    cout << "The power comes out be : " << powerA2B(a, b) << endl;

    return 0;
}