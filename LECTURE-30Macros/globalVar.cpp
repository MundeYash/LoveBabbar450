#include <iostream>
using namespace std;
// concept : Global variable
#define name "yash"
#define PI 3.14

int globalVhai = 56;
void fun1(int a)
{
    cout << a << endl;
    cout << globalVhai << endl;
}
int main()
{

    // a piece of code that is replaced by a value  is macro
    // (Macros cannot be changes while compile time and does not take any memory for its storage )

    double area = PI * 5 * 5;
    cout << "The area of the circle is : " << area << endl;
    string value = name;
    cout << value << endl;
    fun1(3);
    cout << globalVhai << endl;
    return 0;
}