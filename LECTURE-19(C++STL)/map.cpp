#include <bits/stdc++.h>
#include <map> // header file for the map
using namespace std;
// MAP STL in c++ (key value pair , one key point to one value )

int main()
{
    // declaration of map
    map<int, string> mapi;
    // adding values inside the map
    mapi[0] = "nil";
    mapi[1] = "ram";
    mapi[2] = "shyam";
    mapi[3] = "sita";

    // insert value in the map
    mapi.insert({4, "goodBoy"});
    mapi.insert({5, "HeadBoy"});

    // To check whether a value is present or not
    cout << "The 2 is present or not " << mapi.count(-1) << endl;

    // to erase a element from the map
    // to erase key(element )
    mapi.erase(2);

    // to find the element iterator of particular value
    auto it = mapi.find(4);
    // priting the values after the it (iterator )
    for (auto start = it; start != mapi.end(); start++)
    {
        cout << ((*start).first) << " value is: " << (*start).second << endl;
    }

    // printing the map
    for (auto ch : mapi)
    {
        cout << ch.first << "->" << ch.second << endl;
    }

    cout << endl;

    return 0;
}