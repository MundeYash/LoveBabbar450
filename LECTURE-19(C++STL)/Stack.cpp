#include <bits/stdc++.h>
#include <stack> // header file for the stack
using namespace std;

int main()
{
    // declaration of stack (LIFO-> last in first out )
    stack<int> s;
    // adding element in the stack
    s.push(3);
    s.push(31);
    s.push(53);
    // deleting element from the stack
    s.pop();
    // to get the size of the stack
    cout << "Size of the Stack is : " << s.size() << endl;

    // printing in the stack
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "Size of the Stack is : " << s.size() << endl;
    

    return 0;
}