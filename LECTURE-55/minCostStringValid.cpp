// #########IMPORTANT Question :

// Given an string in form of an expression containing the brackets and we need to find the minimum cost to make the expression valid ;
// A string valid if (1. Number of opening brackets = Number of closing brackets ) , (2. closing bracket comes after the opening bracket )and if it is not possible to make valid return -1

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

// function for finding the minimum cost to make string valid
int minCost2Valid(string s)
{
    int n = s.size();

    if (n % 2 != 0)
    {
        // means odd length
        return -1; // not possible to make string valid
    }

    // step 1 : Remove the Valid prat of the string
    stack<char> st;
    int openBracket = 0, closeBracket = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        // same logic of valid parenthesis
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }

        else if (ch == ')' || ch == ']' || ch == '}')
        {
            // remove corresponding open bracket it exists
            char value = findInverse(ch);
            if (!st.empty())
            {
                // opening bracket exists
                if (st.top() == value)
                {
                    st.pop();
                }
            }
            else
            {
                closeBracket++;
            }
        }
    }

    // Step3 : count thesome opening brackets left in the stack
    while (!st.empty())
    {
        openBracket++;
        st.pop();
    }

    int sum = ((openBracket + 1) / 2 + (closeBracket + 1) / 2);
    return sum;
}

int main()
{
    string s = "{}{{{}}}";

    cout << "The minimum cost to make string valid is " << minCost2Valid(s) << endl;
    return 0;
}

/*
Links
gfg : https://www.geeksforgeeks.org/problems/count-the-reversals0401/1       (rem)
code studio : https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTabValue=PROBLEM       (done)
leetcode ; https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/submissions/1161823407/         (done)
interview bit :


other Similiar questions
https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/  (rem)
*/