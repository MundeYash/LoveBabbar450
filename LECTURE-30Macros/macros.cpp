#include <iostream>
using namespace std;
// concept : Macros in the c++
#define name yash
#define PI 3.14
int main()
{

    // a piece of code that is replaced by a value  is macro
    // (Macros cannot be changes while compile time and does not take any memory for its storage )

    
    double area = PI * 5 * 5;
    cout << "The area of the circle is : " << area << endl;
    return 0;
}