#include <iostream>
using namespace std;
// remove all the occurences of given substring in the string
string removeOccurences(string &s, string &part)
{
    while (s.length() != 0 and s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main()
{
    string s;
    cout << "Enter s: ";
    cin >> s;
    string part;
    cout << "Enter substring :";
    cin >> part;
    cout << s << endl;
    cout << part << endl;
    // abc  daabcbaabcbc
    removeOccurences(s, part);

    cout << "AFter removing the substring:";
    cout << s << endl;
}