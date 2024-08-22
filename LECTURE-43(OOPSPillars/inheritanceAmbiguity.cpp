#include<bits/stdc++.h>
using namespace std  ; 

// Inheritance Ambiguity;
class A{
    public:
    void fun(){
        cout<<"calling the class A"<<endl;
    }

};

class B{
    public :
   void fun(){
     cout<<"calling the class B"<<endl;
   }
};

class C : public A , public B {

};
int main(){
    C  object ; 
    object.A::fun();// to overcome the ambiguity 
    object.B::fun();
    return 0 ;
}