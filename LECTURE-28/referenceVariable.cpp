#include <bits/stdc++.h>
using namespace std;

void update(int n)
{ // pass by value (copy of n is created )
    n++;
}

void update2(int &n)
{ //(pass by reference (same memory location of n is pointed with different name ))
    n++;
}

// Reference Variable (same memory location but different names )
int main()
{
    int khushi = 100;
    int &bhakti = khushi;
    cout << "The value of khushi :" << khushi << endl;
    cout << "The value of Bhakti :" << bhakti << endl; //(bhakti is reference name of the khushi )
    int n = 5;
    cout << "Before " << n << endl;
    update(n);
    update2(n);
    cout << "After  " << n << endl;

    return 0;
}