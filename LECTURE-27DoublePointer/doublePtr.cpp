#include <bits/stdc++.h>
using namespace std;

// Pointer to Pointer : Double Pointer Concept
int main()
{
    int a = 5;
    int *ptr = &a;
    int **pptr = &ptr;
    // all these method are same
    cout << "The value of a is :" << a << endl;
    cout << "The value of a is :" << *ptr << endl;
    cout << "The value of a is :" << **pptr << endl;

    //
    cout << "the value at the pointer ptr " << ptr << endl;
    cout << "the value of address of  a " << &a << endl;

    cout << "the value at the  pointer pptr " << pptr << endl;
    cout << "the value of address of  pointer ptr " << &ptr << endl;
  
    
    cout << "The value inside the pointer pptr " << *(pptr) << endl;

    return 0;
}