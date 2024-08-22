#include <bits/stdc++.h>
using namespace std;
// Introduction to the Pointers (POINTERS )

int main()
{
    int a = 5, b = 10;
    // cin >> a >> b;
    int *pa = &a;
    int *pb = &b;

    cout << a << " " << &a << endl;
    cout << b << " " << &b << endl;
    cout << pa << " " << *pa << endl;
    cout << pb << " " << *pb << endl;

    // double pointer
    double d = 133.32;
    double *pd = &d;
    cout << d << " " << pd << " " << &d << " " << (*pd) << endl;

    // float  pointer
    float f = 1363.32;
    float *pf = &f;
    cout << f << " " << pf << " " << &f << " " << (*pf) << endl;

    cout << "Size of pointer is " << sizeof(d) << " " << sizeof(pd) << endl;
    cout << "Size of pointer is " << sizeof(a) << " " << sizeof(pa) << endl;

    // Always intialize the pointer with the null value
    int value = 4;
    int *ptr = 0;
    ptr = &value; // other way of intializing the pointer

    // updating the things via the pointer
    int nums = 10;
    cout << "Before " << nums << endl;
    int *p = &nums;
    *p = *p + 10;
    cout << "After " << nums << endl;

    // copy one pointer to the other
    int *cpy = p;
    cout << cpy << " " << p << endl;
    cout << *cpy << " " << *p << " " << endl;

    // character pointer
    char ch = 'd';
    char *pch = &ch;
    // cout << ch << " " << &ch << " " << pch << " " << (*pch) << endl;

    return 0;
}

/*Similiar Quesiton practice links



*/