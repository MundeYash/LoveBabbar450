// Given a stack and we need to return the reverse order of the elements present in the stack
#include <bits/stdc++.h>
using namespace std;

// function for reversing the stack
// helper function for recursion call

void insertBottom(stack<int>&s , int x ){

    if (s.empty()){
        s.push(x);
        return ;
    }

    int num = s.top();
    s.pop();
    // call for recurion 
    insertBottom(s,x);
    s.push(num);
}
void solve(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    // work 

        // Step1 : Store the element before the next function call 
    int num = s.top();
    s.pop();
    
    // next call 
    solve(s);
   
    // step2 insert at the bottom
    insertBottom(s,num);
    
}
void reverseStack(stack<int> &s)
{

    //concept : Recursion and Insert the element at the bottom 

    solve(s);// time : O(N^2) , space : (H->recursive stack space)
    
    return;
}
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    for (int i = 1; i <= 10; i++)
    {
        s.push(i);
    }
    print(s);

    // after reversal
    reverseStack(s);
    print(s);

    return 0;
}
/*
Links : 
gfg: https://www.geeksforgeeks.org/problems/reverse-a-stack/1 (done)
code studo : https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION (done)
interviewBit ; 
Leetcode:

//
Extra question 
https://www.geeksforgeeks.org/problems/decode-the-string2444/1      (rem)
*/