#include <bits/stdc++.h>
#include <set> // header file for the set
using namespace std;

int main()
{// Stores only the unique elements 

    // declaration of set
    set<int> s;
    // adding / inserting element inside the set
    s.insert(1);
    s.insert(12);
    s.insert(11);
    s.insert(15);
    s.insert(51);
    // printing the elements in the set
    for (auto ch : s)
    {
        cout << ch << " ";
    }
    cout << endl;
    //(Set will generate the output in the sorted form )
    // deleting the values form the set
    s.erase(s.begin());
    s.erase(s.end());
    // Erasing the element at any particular position

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     if (*(it) == 15)
    //     {
    //         s.erase(it);

    //     }
    // }

    for (auto ch : s)
    {
        cout << ch << " ";
    }
    cout << endl<<"aya";

    // to check whether a particular element is present in set or not
    cout<<s.count(12)<<endl;

    // to get the ITERATOR of value to be searched 
    // auto itr = s.find(12);
    // cout<<"value of itr is :" <<*(itr)<<endl;
    return 0;
}