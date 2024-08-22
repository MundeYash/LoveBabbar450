#include <bits/stdc++.h>
using namespace std;
// PROBLEM :Reversing a words in given string
string reverseWords(string &S)
{
    // concept L:using a stack for solving the problem
    stack<char> stk;
    for (int i = 0; S[i] != '\0'; i++)
    {
        if (S[i] == ' ')
        {

            if (S[i + 1] != ' ')
            {
                stk.push(S[i]);
            }
            else
            {
                continue;
            }
        }
        else
        {
            stk.push(S[i]);
        }
    }

    // taking the elements out of the stack
    string ans;
    string finalAns;

    while (!stk.empty())
    {
        char value = stk.top();
        if (value == ' ')
        {
            reverse(ans.begin(), ans.end());
            finalAns += ans;
            finalAns.push_back(' ');
            ans.clear();
        }
        else
        {
            ans.push_back(value);
        }
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    finalAns += ans;
    return finalAns;
}

int main()
{
    string s;
    getline(cin, s);

    cout << s << endl;

    string ans = reverseWords(s);
    // cout << s << endl;
    cout << ans << endl;
    return 0;
}