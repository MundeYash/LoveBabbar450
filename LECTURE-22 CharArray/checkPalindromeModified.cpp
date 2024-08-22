/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

char ToLowerCase(char ch)
{
    return (ch - 'A' + 'a');
}
bool isPalindrome(string s)
{
    // edge case

    vector<char> ans;
    int n = s.size();
    if (n == 1 and s[0] == ' ')
    {
        return true;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        char value = s[i];
        if ((value >= 'A' and value <= 'Z'))
        {
            ans.push_back(ToLowerCase(value));
        }
        if ((value >= 'a' and value <= 'z') || (value >= '0' and value <= '9'))
        {

            ans.push_back(value);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    int start = 0, end = ans.size() - 1;
    while (start <= end)
    {
        if (ans[start] != ans[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    string s = "tooT";
    cout << isPalindrome(s);

    return 0;
}