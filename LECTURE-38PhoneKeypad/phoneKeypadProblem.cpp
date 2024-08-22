

#include <bits/stdc++.h>
using namespace std;

// Phone Keypad Problem / Letter Combination of Phone number  :   given a string containing numbers from the 0 to 9 and return the possible answer string of arrays to be generated
// time complexity :O(4^n)
void solve(string digits, string output, int index, vector<string> &ans, string mapping[10])
{
    // base case
    int n = digits.length();
    if (index >= n)
    {
        ans.push_back(output);
        return;
    }

    // work

    // recursive case

    int number = digits[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.size(); i++)
    {
        output.push_back(value[i]);
        solve(digits, output, index + 1, ans, mapping);
        // after doing it for one character just backTrack it
        output.pop_back();
    }
}
// This is main phone Keypad function
vector<string> PhoneKeypad(string digits)
{
    int n = digits.size();
    string output = "";

    vector<string> ans;

    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};// here maximum string length = 4 
    solve(digits, output, index, ans, mapping);
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

    string a = "234";
    int n = a.size();

    vector<string> ans = PhoneKeypad(a);

    print(ans, ans.size());

    return 0;
}
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/983619723/ (done )
// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1 (done )
// https://www.codingninjas.com/studio/problems/letter-combinations-of-a-phone-number_983623?leftPanelTab=0 (done)

