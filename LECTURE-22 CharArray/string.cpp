#include <iostream>
using namespace std;
int main()
{
    char c[10] = "coding\0";
    string s = "coddingmroign";
    s[5] = '\0' ;
    cout << c << endl;
    cout << s << endl;

//     string si ; 
//      getline(cin,si);
//     char ch [10]; 
//    cin.getline(ch,10);
//    cout<<si<<endl;
//    cout<<ch<<endl;


    return 0;
}