#include<iostream>
using namespace std ;
// Polymorphism means many forms of a same thing 
// Types of polymorphism --->(Run time , Compile Time (function Overloading , Operator Overloading ))


// Accessing the same function in same class with same name but different agruments , numbers of arguments and types of arguments are Function overloading 
//like 
// Implementation of Complile time Polymorphism --



//Function Overloading 
class A{
public : 
void fun1 (){
    cout<<"Yeah chal raha hai " ;
}
void fun1 (string s ){
    cout<<"Yeah chal raha hai " ;
    cout<<s<<endl;
}
int fun1 ( int n , string s   ){
    cout<<"Yeah chal raha hai " ;
    cout<<n<<s<<endl;
}
int fun1 (string s , int n , int a=0 , int b=5   ){
    cout<<"Yeah chal raha hai " ;
    cout<<n<<s<<endl;
}
int fun1 (string s , int n , char ch  ){
    cout<<"Yeah chal raha hai " ;
    cout<<n<<s<<endl;
}
 
};

//Operator Overloading -----> changing the functionality of a particular operator and change according to the need using same symbol is operator overloading
class B{

    public: 
    int a , b ; 
     int add (){
        return a+ b ; 
     }
      // changing the use of (+)
       void operator+(B &obj) // + is binary operator 
       {
            int value1 = this-> a ; 
            int value2 = obj.a ; 
            cout<<value2 - value1<<endl;
       }
    void operator()(){
        cout<<"I am Bracker Operator"<<this->a;
    }
   
} ; 
int main (){
     
    // A one  ; 
    // one.fun1( 6, "heel" ) ; 

    B obj1 , obj2 ; 
    obj1.a = 4 ; 
    obj2.a = 7; 
    // find the result of obj1 + obj2 
     obj1 + obj2 ; 
    cout<<"The Result after Operator overloading of plus operator is " <<endl;
         obj1() ; 


     cout<<"\nThis is About Polymorphism in c++\n" ; 
    return 0 ;
}