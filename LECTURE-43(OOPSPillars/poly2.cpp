#include <iostream>
using namespace std;

// Poly morphism (same name with many forms )
class A
{
public:
    // function overloading
    void sayHello()
    {
        cout << "hello good morning " << endl;
    }
    void sayHello(string s)
    {
        cout << "hello 2 wala  " << endl;
    }

    void sayHello(int a, string s)
    {
        cout << "Say hello" << endl;
    }

    void sayHello(string s, int a)
    {

        return;
    }
};
int main()
{
    A *suresh = new A;
    suresh->sayHello();
    // A raman;
    // raman.sayHello();
    // raman.sayHello("ys");
    // raman.sayHello(2, "hd");

    return 0;
}