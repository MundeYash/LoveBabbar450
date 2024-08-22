
#include <bits/stdc++.h>
using namespace std;

//  Permutation of String    :   given a string , we need to generate all the possible permutation of string using the recursion
void solve(string nums, int index, vector<string> &ans)
{
    // base case
    int n = nums.size();
    if (index >= n)
    {
        ans.push_back(nums);
        return;
    }

    // recursive case
    for (int j = index; j < n; j++)
    {
        swap(nums[index], nums[j]);
        solve(nums, index + 1, ans);

        // backtracking
        swap(nums[index], nums[j]); // just like removing the answer popback
    }
}

vector<string> Permutation(string nums)
{
    vector<string> ans;
    //   recurPermute(0, nums, ans);
    solve(nums, 0, ans);

    sort(ans.begin(), ans.end()); // for printing all the generated string in lexographically increasing order

    return ans;
}
void print(vector<string> ans, int n)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    string a = "ABC";
    int n = a.size();

    vector<string> ans = Permutation(a);

    print(ans, ans.size());

    return 0;
}
