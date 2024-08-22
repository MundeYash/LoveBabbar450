#include <bits/stdc++.h>
#include <list> // header file for the list
//(It is implemented using the doubly link list )
using namespace std;

int main()
{
    // declaration of list
    list<int> l(4, 10);
    // printing the list
    for (auto ch : l)
    {
        cout << ch << " ";
    }
    cout << endl;
    // to add element in the list

    l.push_back(3);
    l.pop_front();
    l.push_front(10);
    // To remove element in the list
    l.pop_back();
    // to Delete /erase particular element
    l.erase(l.begin());

    // To get the size of the list
    cout << "Size is : " << l.size() << endl;

    // to delete all the elements
    l.clear();

    // to check whether our list is empty or not
    cout << "The list is : " << l.empty() << endl;
    return 0;
}