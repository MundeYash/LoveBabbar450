#include <bits/stdc++.h>
#include <queue> // header file for the queue
using namespace std;

int main()
{
    //(FIFO-> first In first Out  )
    // decllaration of queue
    queue<int> q;
    q.push(3);
    q.push(32);
    q.push(31);
    q.push(311);
    cout << "To get size of the queue " << q.size() << endl;

    // printing the elements of queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    // to get the size of the queue
    cout << "To get size of the queue " << q.size() << endl;
    return 0;
}