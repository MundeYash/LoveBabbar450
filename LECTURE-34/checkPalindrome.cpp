#include <bits/stdc++.h>
using namespace std;

// OUTPUT Print
void print(vector<int> &a)

{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
vector<int> toBinary(long long n)
{
    vector<int> ans;
    while (n != 0)
    {
        int ld = n & 1;
        // ans = ans * 10 + ld ;
        ans.push_back(ld);
        n = n / 10;
    }
    // reverse(ans.begin(), ans.end());
    return ans;
}

bool palindromeRec(vector<int> a, int s, int e)
{
    // iterative , Time = O(n) , space : O(1)
    // base case
    if (s > e)
        return true;

    if (a[s] != a[e])
        return false;

    return palindromeRec(a, s + 1, e - 1);
}
bool palindromeRecSimple(string &a, int s, int e)
{
    // recursive time : O(n) ,space : O(n)
    // base case
    if (s > e)
        return true;

    if (a[s] != a[e])
        return false;

    else
    {
        return palindromeRecSimple(a, s + 1, e - 1);
    }
}
int main()
{
    long long n = 1;
    vector<int> ans = toBinary(4);
    string a = "naman";
    cout << a << endl;
    cout << "The given String is : " << palindromeRecSimple(a, 0, a.size() - 1) << endl;
    cout << a << endl;

    // print(ans);
}