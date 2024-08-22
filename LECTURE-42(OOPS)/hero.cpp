#include<iostream>
using namespace std ; 


class Hero
{
private:
    // default constructor (mannually creation )
    // Hero()
    // {
    //     cout << "Inside the default constructor " << endl;
    // }

    // some of properties of class 
    char name[100];
    int health;
    char level;
    float f;

    void print()
    {
        cout << "The level is :" << level << endl;
        cout << "The health  is :" << health << endl;
    }

    void setLevel(char ch)
    {
        level = ch;
    }
    void getLevel()
    {
        cout << level << endl;
    }
};