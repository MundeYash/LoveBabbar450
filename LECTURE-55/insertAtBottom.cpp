// Given an stack and an element . we need to push the element at the bottom of the given stack

#include <bits/stdc++.h>
using namespace std;

void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Function for inserting the element at the bottom of the stack
// helper function
void solve(stack<int> &s, int x)
{
    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }
    // recursive case
    int num = s.top();
    s.pop();
    solve(s, x);
    s.push(num);
}
stack<int> insertBottom(stack<int> &s, int x)
{
    // time : O(n) , space : O(h) h-> recursive stack space 
    
    solve(s, x);
    return s;
}
int main()
{
    stack<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }
    print(s);
    insertBottom(s, 10);
    print(s);

    return 0;
}

/*
Links :
gfg : https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1 (done)
codestudio : https://www.codingninjas.com/studio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM (done)
interview Bit :
leetcode :

*/