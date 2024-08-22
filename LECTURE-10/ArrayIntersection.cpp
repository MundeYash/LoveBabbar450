#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
// Program to find the intersection of the two sorted arrays
void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
// function for finding the intersection array

// METHOD 1 : Brute force

vector<int> intersection2(vector<int> a, int n, vector<int> b, int m)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {

        int value = a[i];

        for (int j = 0; j < m; j++)
        {
            if (b[j] == value)
            {
                b[j] = -1;
                ans.push_back(value);
            }
        }
    }

    return ans;
}

// METHOD2 : Two Pointers Approach
vector<int> intersection(vector<int> a, int n, vector<int> b, int m)
{
    // Two pointer approach
    vector<int> ans;
    int i = 0, j = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while (i <= n and j <= m)
    {
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            a[i] = -1;
            i++;
            j++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return ans;
}
// function for printing the array
void print(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    vector<int> a = {1, 2, 4, 5, 11, 10, 100};
    int n = a.size();

    vector<int> b = {3, 1, 1, 10, 3, 5, 100, 11};
    int m = b.size();

    vector<int> ans;
    ans = intersection2(a, n, b, m);
    print(ans, ans.size());

    return 0;
}