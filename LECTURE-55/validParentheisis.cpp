// IMportant Question(Mostly Asked in OA and interviews ) :
//  Given a string containg only the different types of brackets . You need to check whether the string is valid string or not means (given order of brackets are correct and complete )
#include <bits/stdc++.h>
using namespace std;
char findInverse(char ch)
{
    char ans;
    if (ch == ')')
    {
        ans = '(';
    }
    else if (ch == ']')
    {
        ans = '[';
    }
    else if (ch == '}')
    {
        ans = '{';
    }
    return ans;
}
bool isValid(string s)
{
    // concept : Use stack : push every open bracket into the stack for close bracket check its inverse on the top
    // time : O(N) , space : O(N)
    stack<char> st;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            // for open brackets
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // for close bracket inverse
            char value = findInverse(ch);
            if (st.empty())
            {
                return false;
            }
            else
            {
                // means stack has some spaces
                char topValue = st.top();
                st.pop();
                if (topValue != value)
                {
                    return false;
                }
            }
        }
    }

    if (s.empty()== false )return false;
    return true;
}
int main()
{
    string s = "()[]{"; // valid expression

    string s2 = "{)"; // not valid
    if (isValid(s2))
    {
        cout << "Valid Expresssion" << endl;
    }
    else
    {
        cout << "Not Valid Expression " << endl;
    }

    return 0;
}
/*
Links :
leetcode : https://leetcode.com/problems/valid-parentheses/ (done)
codestudio ; https://www.codingninjas.com/studio/problems/valid-parentheses_795104 (done)
interview bit :
gfg : https://www.geeksforgeeks.org/problems/valid-expression1025/1 (done)



Extra Links (similiar Question for the practice )

https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1         (done)
https://www.geeksforgeeks.org/problems/get-min-at-pop/1          (done)(MIN_STAck Type question)
https://www.geeksforgeeks.org/problems/find-equal-point-in-string-of-brackets2542/1      (rem)

https://www.geeksforgeeks.org/problems/valid-substring0624/1            (rem)
 
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/1161821947/     (done)
*/