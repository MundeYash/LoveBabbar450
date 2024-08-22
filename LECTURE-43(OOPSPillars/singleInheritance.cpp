#include <iostream>
using namespace std;

// single level inheritance

class animal
{
public:
    int age;
    int weight;

    void bark()
    {
        cout << "Animal Speaking" << endl;
    }
};

class dog : public animal // animal-> dog
{                         // this is single inheritance
};

// Type 2 -> multi-level inhertance

class germanSpherad : public dog // animal->dog-> germanSpherad
{
};

// Type 3 :Multiple inheritance :

class human
{
public:
    void speak()
    {
        cout << "Speaking human" << endl;
    }
};


// Multiple- Inheritance 
class Hybrid : public animal, public human
{
};


// type5:Heirarchical Inheritance 
class A{
    public:
    void fun1(){
        cout<<"Inside the function 1 "<<endl;
    }

};

class B:public A{
    public: 
    void fun2(){
        cout<<"Inside the function 2 "<<endl;
    }

};

class C :public A{
    public:
    void fun3 (){
        cout<<"Inside the function 3 "<<endl;
    }
};

// hybrid Inheritance : inheritance combination of more than two or more type of inheritance 

int main()
{
    // Hybrid h1;
    // h1.bark();
    // h1.speak();




    // heirarchical inheritance 
    A obj1 ; 
    obj1.fun1();

    B obj2 ; 
    obj2.fun1() ;
    obj2.fun2();

    C obj3 ; 
    obj3.fun1() ; 
    obj3.fun3();
    return 0;
}