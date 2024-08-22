// Important Question

// Given a stack and we need to sort the stack without using the loops and any inbuild function for sorting it

#include <bits/stdc++.h>
using namespace std;

// helper function for inserting the element in the stack in the sorted form
void sortedInsert(stack<int> &s, int x)
{
    // base
    if (s.empty() || (!s.empty() and s.top() < x))
    {
        s.push(x);
        return;
    }
    // work
    int num = s.top();
    s.pop();

    // recursive case
    sortedInsert(s, x);

    // again push the inserted element back to the stack
    s.push(num);
}

void sortStack(stack<int> &s)
{
    // time : O(n^2) , space : O(h-> recursive stack space )
    // base case
    if (s.empty())
    {
        return;
    }

    // work
    int num = s.top();
    s.pop();

    // recursive case
    sortStack(s);

    // after comming back (push in the sorted way )

    sortedInsert(s, num);
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
    s.push(100);
    s.push(0);
    s.push(-20);
    print(s);
    sortStack(s);
    cout << "AFter sorting : " << endl;
    print(s);
    return 0;
}

/*
Links :
gfg :  https://www.geeksforgeeks.org/problems/sort-a-stack/1 (done)
leetcode :
code studio : https://www.codingninjas.com/studio/problems/sort-a-stack_985275 (rem)
interview bit :

*/