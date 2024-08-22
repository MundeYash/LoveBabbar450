#include <bits/stdc++.h>
using namespace std;
// Subsets (array/strings ) :   Given an array and find all the possible subsets of the array  .
// time : O(2^n ),space : O(N^2)

void print(vector<vector<int>> ans, int n)
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

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    int n = nums.size();
    if (index >= n)
    {
        ans.push_back(output);
        return;
    }

    // work

    // recursive case

    // exclude (direct next index ke liye call kardo )
    solve(nums, output, index + 1, ans);

    //  include case (next index ke liy call karo + current index ko include karo )

    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);

    return ans;
}

int main()
{

    vector<int> a = {1, 2, 3};
    int n = a.size();

    vector<vector<int>> ans = subsets(a);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    print(ans, ans.size());
    cout << "The number of possibls subsets " << ans.size() << endl;

    return 0;
}
//
/*
https://www.codingninjas.com/studio/problems/unique-subsets_3625236 (done )
//https://leetcode.com/problems/subsets-ii/ (done )
// https://www.codingninjas.com/studio/problems/find-all-subsets_2041970?leftPanelTab=1 (done )
https://practice.geeksforgeeks.org/problems/subsets-1613027340/0?category=
*/
