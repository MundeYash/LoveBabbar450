// this question will be solved using the stack and the two pointer approach
#include <bits/stdc++.h>
using namespace std;

// time complexity :o(n) , space complexity :O(n)

// function for removing the adjacent duplicates elements
string removeAdjacentDuplicate(string s)
{
    int n = s.length();

    // creating a string  ans for storing the final ans
    string ans;
    ans.push_back(s[0]);

    for (int i = 1; i < n; i++)
    {
        if (s[i] == ans.back())
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[i]);
        }
    }

    return ans;
}
// concept used : string_name.back()-> function for the last element in the string
int main()
{
    string s;
    getline(cin, s);

    cout << s << endl;
    cout << "After removing the duplicates elements from the string :" << removeAdjacentDuplicate(s) << endl;
    return 0;
}