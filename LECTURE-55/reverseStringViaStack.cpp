// Reverse the given string using the stack
#include <bits/stdc++.h>
using namespace std;
void reverseString(string &s)
{
    stack<char> sk;

    // step1 : push the all the characters of the string into the stack
    for (int i = 0; s[i] != '\0'; i++)
    {
        sk.push(s[i]);
    }

    // step2 :  just take out each  element from the stack and append it to string and it  will be reverse order
    s.clear();
    while (!sk.empty())
    {
        s.push_back(sk.top());
        sk.pop();
    }
    return;
}
int main()
{
    string s = "yash";
    cout << s << endl;

    cout << "After the Reversal " << endl;
    reverseString(s);
    cout << s << endl;
    return 0;
}

/*
Link :
gfg :
code studio : https://www.codingninjas.com/studio/problems/reverse-the-string_799927?leftPanelTabValue=SUBMISSION(done)
interview bit :
leetcode :
*/