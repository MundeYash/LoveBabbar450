// Important Question :similiar to Valid parenthesis

// Given an expression containing operators , brackets and english lowercase characters and numbers . we need to check whether the expression contains the redundant brackets or not (redundant brackets are extra needless brackets in the expresssion )
#include <bits/stdc++.h>
using namespace std;
// function for giving the corresponding inverse closed brackets
char inverseBracket(char ch)
{
    char ans;
    if (ch == ')')
    {
        ans = '(';
    }
    else if (ch == '}')
    {
        ans = '{';
    }
    else if (ch == ']')
    {
        ans = '[';
    }
    return ans;
}
bool checkRedundant(string s)
{
    // concept: Stacks -> for each opening brackets and operators we push them into the stack and for each closing brackets we check till the stack top contains the inverse opening bracket correspondingly or not
    // Time complexity : O(N), space : O(N)-due to stack space 
    stack<char> st;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        // Step1 : if the current character of string is open bracket or Operator push it into the stack 
        if ((ch == '(' || ch == '{' || ch == '[') || (ch == '+' || ch == '-' || ch == '*' || ch == '/'))
        {
            // for opening brackets and operators
            st.push(ch);
        }
        // step2 : Check if character is the closed bracket (means on expression is compelte )
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            // for closing brackets
            char value = inverseBracket(ch);
            // checking parameter
            bool isRedundant = true;

            // step3 : check till we don't find the corresponding open bracket if get any operator than it is valid bracket other it is redundant 
            while (st.top() != value)
            {

                char topValue = st.top();
                if (topValue == '+' || topValue == '-' || topValue == '*' || topValue == '/')
                {
                    isRedundant = false;
                }
                st.pop();
            }
            if (isRedundant)
                return true;
            st.pop(); // for removing previously checked open bracket
        }
    }
    return false;
}
int main()
{
    string s = "(a+c*b)+(c))";
    string s2 = "(a+b)";
    cout << checkRedundant(s) << endl;
    cout << checkRedundant(s2) << endl;

    return 0;
}
/*
Links :
gfg :
leetcode : https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1        (done)
code studio : https://www.codingninjas.com/studio/problems/redundant-brackets_975473?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM      (done)
interview bit :


Similiar Question : (hard category ): https://www.geeksforgeeks.org/problems/redundant-parenthesis--170647/1         (rem)

*/