#include <iostream>
using namespace std;
class Student
{
public:
  char name;
  int age;
  char fathers_name[100];
  char mothers_name[100];

private:
  char gender;
  int rank;

  int getAge()
  {
    return this->age;
  }
};

// Inheritance
class human
{ // human is our parent class
public:
  char name;
  int age;
  int weight;
  int height;
};

class male : public human
{
public:
  int available_time;
  int getTime()
  {
    return this->available_time;
  }
};
class female : public human
{
public:
  int free_time;
  int getTime()
  {
    return this->free_time;
  }
};

class student
{
private:
  // properties
  string name;
  int age;
  int height;

public:
  int getAge()
  {
    return this->age;
  }
};
int main()
{
  // Polymorphism

  // Inheritance -----> inheritance of characteristics
  // this is like Parent Class (Super class )and Child class
  // format of accessing a class
  // chlid class : accesmodifier like public parent class

  //     // different modees of inheritence like public , private and protected mode of inheritance

  // human h1 ;
  // // this is for human class
  //  cout<<endl;
  //  cout<<"For human Class\n" ;
  // cout<<h1.name<<endl;
  // cout<<h1.age<<endl;
  // cout<<h1.weight<<endl;
  // cout<<h1.height<<endl;
  //  cout<<endl;
  // male m1 ;
  // // this for male class

  //  cout<<endl;
  //  cout<<"For male Class\n" ;
  // cout<<m1.name <<endl;
  // cout<<m1.age <<endl;
  // cout<<m1.weight <<endl;
  // cout<<m1.height <<endl;
  // cout<<m1.available_time<<endl;
  // cout<<endl;

  // // this is for female class

  //  cout<<endl;
  //   cout<<"For Female Class\n" ;
  // female f1 ;
  // cout<<f1.name <<endl;
  // cout<<f1.age<<endl;
  //  cout<<f1.weight<<endl;
  //  cout<<f1.height<<endl;
  //  cout<<f1.free_time<<endl;
  //   cout<<endl;
  //   // Parent class type ----> child class ----> Result

  //   /* public ---->public ---->   acess like  public
  //     public ----> protected ----> acess like protected
  //     public ----> private ---> not acessible

  // // protected data memebers are like public  ---> access inside the class and in their derived child class
  //     protected -----> public ----->  access like protected
  //       protected -----> protected -----> access like protected
  //         protected ----->  private -----> not accessible

  //     private----> public ----->  not accessible
  //     private----> protected ----->  not accessible
  //     private---->  private ----->  not accessible
  //   */

  // // Types of Inheritance
  // /* 1. Single Inheritance  A----> B
  //  2. Multi-Level Inheritance  A----->B , B------>C ,C------>D
  //  3. Multiple Inheritance A , B , A---------->C,B------------>C ;
  //  4. Heirarchical Inheritance
  //  5. Hybrid Inheritance
  // */
  //      cout<<"This is Lecture No -43 oops continue\n" ;
  //      cout<<"\n ENCAPSULAITON , INHERITENCE , POLY-MORPHISM , ABSTRACTION \n" ;

  student a;
  return 0;
}