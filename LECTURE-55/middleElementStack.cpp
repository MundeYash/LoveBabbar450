#include <bits/stdc++.h>
using namespace std;

/*
How to implement a stack which will support the following operations in O(1) time complexity?
1) push() which adds an element to the top of stack.
2) pop() which removes an element from top of stack.
3) findMiddle() which will return middle element of the stack.
4) deleteMiddle() which will delete the middle element.
*/
class Stack
{
public:
    int *arr;
    int top;
    int size;

    // constructor
    Stack(int n)
    {
        size = n;
        arr = new int[size];
        top = -1;
    }

    // push operation
    void push(int value)
    {
        if (top + 1 <= size - 1)
        {
            arr[++top] = value;
        }
        else
        {
            cout << "Stack is Overflow ";
        }
    }

    // pop operation
    void pop()
    {
        if (top > -1)
        {
            top--;
        }
        else
        {
            cout << "Stack is Underflow ";
        }
    }

    // find middle element
    int middle()
    {
        if (top == -1)
        {
            cout << "Stack is empty ";
        }
        else
        {
            return arr[top / 2];
        }
    }

    // delete middle element (o(n ) this is taking linear time not constant time )
    void deleteMiddle()
    {
        if (top == -1)
        {
            cout << "Stack is empty ";
        }
        else
        {
            // shifting of element
            for (int i = top / 2; i < top; i++)
            {
                arr[i] = arr[i + 1];
            }
            top--;
        }
    }
};
int main()
{
    Stack st(6);
    st.push(3);
    st.push(13);
    st.push(32);
    st.push(23);
    st.push(35);

    st.push(35);
    st.push(43);
    st.pop();
    cout << st.middle() << endl;
    st.deleteMiddle();
    cout << st.middle() << endl;

    return 0;
}