#include <iostream>
#include <map>
#include<unordered_map>

using namespace std;

int main()
{
    // creation of map
    map<int, int> mp;

    // insertion
    pair<int, int> p = make_pair(9, 10);
    mp.insert(p);

    pair<int, int> p2(81, 9);
    mp.insert(p2);

    mp[49] = 7;
    cout << mp.at(49) << endl;
    cout << mp[9] << endl;

    // SEARCHING: count function : to check whether the particular is present in the map or not
    cout << mp.count(49) << endl; // present
    cout << mp.count(91) << endl; // not present

    // find function() ;
    if (mp.find(9) != mp.end())
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "NOt found " << endl;
    }

    // size function to get the size of the map
    cout << "The size of the map is : " << mp.size() << endl;
    cout << mp[71] << endl; // random value : here the first the value with the random value is created and than it will update the size
    cout << mp.size() << endl;

    // iteration over map :

    for (auto i : mp)
    {
        cout << i.first << "->" << i.second << endl;
    }

    // implementation of hashMap:

    string s = "thiruvananthapuram";

    // ques1: find the number of occureces of each character in the string

        map<char, int> c;
    for (int i = 0; i < s.size(); i++)
    {
        c[s[i]]++;
    }

    // print:
    for (auto it : c)
    {
        cout << it.first << "->" << it.second << endl;
    }

    // ques2 : check whether a link list is ciruclar or not + contains any loop or not 
    
    unordered_map<node*> 

    cout << "\nThis is working and everything is fine " << endl;
    return 0;
}