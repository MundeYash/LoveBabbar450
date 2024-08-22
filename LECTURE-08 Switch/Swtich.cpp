#include <bits/stdc++.h>
using namespace std  ; 
int main()
{
    char ch ; 
    cin>> ch ; 
    // implementation of switch case statement 
    //** We can not use continue statement in the switch case 
    switch (ch)
    {
    case 'A' :
    cout<<"This is A value ";
        break;

           case 'B' :
    cout<<"This is B value ";
        break;

           case 'C' :
    cout<<"This is C  value ";
        break;


           case 'D' :
    cout<<"This is D  value ";
        break;

           case 'E' :
    cout<<"This is  E value ";
        break;
    
    default: cout<<"Compulsory default Statement "<<endl;
       break  ; 
    }
    cout << "\nSwitch Cases " << endl;
    return 0;
}