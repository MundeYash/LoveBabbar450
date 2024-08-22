

#include <bits/stdc++.h>
using namespace std;
// Subsets (array/strings ) :   Given an array and find all the possible subsets of the array  .

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

void solve(string nums, string output, int index, vector<string> &ans)
{
    // base case
    int n = nums.size();
    if (index >= n)
    {
        if (output.length() > 0)
            ans.push_back(output);
        return;
    }

    // work

    // recursive case

    // exclude (direct next index ke liye call kardo )
    solve(nums, output, index + 1, ans);

    //  include case (next index ke liy call karo + current index ko include karo )

    char element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}

vector<string> subsequences(string str)
{

    // Write your code here
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);

    return ans;
}

int main()
{

    string a = "abc";
    int n = a.size();

    vector<string> ans = subsequences(a);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    print(ans, ans.size());

    return 0;
}
/*
https://www.codingninjas.com/studio/problems/print-subsequences_624391?leftPanelTab=0 (done )
https://www.codingninjas.com/studio/problems/subsequences-of-string_985087 (done)
https://practice.geeksforgeeks.org/problems/string-subsequence-game5515/1 (done)


*/