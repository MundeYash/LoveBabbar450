#include <bits/stdc++.h>
using namespace std;
// Union of Two Arrays : Given Two different arrays and we need to find the union (all the elements from both the arrasy only one time occurence )as union
vector<int> unionArrays1(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> ans;

    // step 1: mark the intersecting elements to the INT_MIN and than copy the elements

    for (int i = 0; i < n; i++)
    {
        int element = a[i];
        for (int j = 0; j < m; j++)
        {
            if (b[j] == element)
            {
                b[j] = INT_MIN;
            }
        }
    }

    // step 2 : copy the elements from both arrays
    for (int i = 0; i < n; i++)
    {
        ans.push_back(a[i]);
    }

    for (int j = 0; j < m; j++)
    {
        if (b[j] != INT_MIN)
            ans.push_back(b[j]);
    }

    return ans;
}

vector<int> unionArrays2(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n and j < m)
    {
        if (a[i] != b[j])
        {
            ans.push_back(a[i]);
            ans.push_back(b[j]);
            i++;
            j++;
        }
        else if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}
void print(vector<int> a)
{
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> a = {1, 3, 5, 7, 11};
    vector<int> b = {2, 4, 7, 6, 8, 10};

    vector<int> ans = unionArrays2(a, b);
    print(a);
    print(b);
    print(ans);

    return 0;
}