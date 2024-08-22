#include <bits/stdc++.h>
using namespace std;
// approach -1 T:O(N^2)
vector<pair<int, int>> pairSum(vector<int> &a, int k)
{
    vector<pair<int, int>> ans;
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = (i + 1); j < n; j++)
        {
            int sum = a[i] + a[j];
            if (sum == k)
            {
                pair<int, int> temp;
                temp.first = a[i];
                temp.second = a[j];
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

// approach -2 (time complexity : o(n))

vector<pair<int, int>> pairSum2(vector<int> &a, int k)
{
    vector<pair<int, int>> ans;
    int n = a.size();

    sort(a.begin(), a.end());
    // 2 pointers concept
    int s = 0, e = n - 1;
    while (s < e)
    {
        int sum = a[s] + a[e];
        if (sum == k)
        {
            pair<int, int> temp;
            temp.first = a[s];
            temp.second = a[e];
            ans.push_back(temp);
            s++;
            e--;
        }

        else if (sum > k)
        {
            e--;
        }
        else
        {
            s++;
        }
    }

    return ans;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    int n = a.size();
    int k = 7;

    vector<pair<int, int>> ans = pairSum(a, k);
    // vector<pair<int, int>> ans = pairSum2(a, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
/*
gfg : https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1(rem)
*/