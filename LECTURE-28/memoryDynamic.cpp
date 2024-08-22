#include <iostream>
using namespace std ;

// Dynamic Memory allocation : (Heap Memory which will accessed via the pointers and created using the new keyword )
//WE have to delete the dynmaic created memory because static is automatically deleted while the heap memory stays store untill deleted 
int main()
{

    // static variable creation
    int a = 5;
    cout << a << endl;

    // dynamic variable creation

    // integers
    int *a1 = new int;
    *a1 = 5;
    cout << *a1 << endl;

    // float data- type
    float f = 54.35;
    cout << f << endl;
    float *f1 = new float;
    *f1 = 893.321;
    cout << *f1 << endl;

    // double data type
    float d = 541.35;
    cout << d << endl;
    float *d1 = new float;
    *d1 = 81193.321;
    cout << *d1 << endl;

    // bool data type
    bool result = false;
    cout << result << endl;

    // bool type pointer 
    bool *result1 = new bool ; 
    *result1 = true ;
    cout<<*result1<<endl;


    // dynamically array creation 
    int arr[] ={23,3,1,1,100} ; 

    // via pointer dynamically 
    int n ; 
    cin>> n; 
    int *a = new int[n] ;//  here a variable sized array is created 
    // *a ={2,3,5,11,1001,10} ;

}