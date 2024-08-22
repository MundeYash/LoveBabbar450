#include<iostream>
using namespace std ; 

// ********Types of Inheritance 
/* 1. Single Inheritance  A----> B
 2. Multi-Level Inheritance  A----->B , B------>C ,C------>D
 3. Multiple Inheritance A , B , A---------->C,B------------>C ;  
 4. Heirarchical Inheritance 
 5. Hybrid Inheritance  
*/
 class A{
    public :
    void call(){
        cout<<"calling the A\n" ; 
    }
 } ; 

 class B{
    public : 
    void call(){
        cout<<"calling the B"<<endl;
    }
 } ;

 class c: public A, public B{
    public:
    void hello(){
        cout<<"HELLO \n" ;
    }
 } ;
class animal { // parent class 
    public: 

    char type ;
    char getType(){
        return this-> type ; 
    }
     void tell(){
        cout<<"telling"<<endl;
     }
};
 

class human {// another Parent class 
    public : 
    int Iq ; 
     int weight  ;
     int height ; 
     void call(){
        cout<<"Calling the Human \n" ; 
     } 
};
//Single Inheritance 
class dog :public animal {  // child class of parent animal 
    
     public :
     void barking(){
        cout<<"Barking"<<endl ; 
    }
};
// MUlti -Level Inheritance 
 class Labra: public dog{// parent class of dog child  class 
public : 
char color ; 
void breed (){
    cout<<"Breed of Labra\n" ; 
}

 } ; 

// MultiPle inheritance 
class monkey :public human , public animal {
    public : 

    char color ; 
    int design ; 
    void dance(){
        cout<<"Monkey is dancing \n" ; 
    }
};


class bandar : public  monkey {
     public : 
       int value ; 
     void name (){
        cout<<"HEHEH ---> Bandar \n" ; 
     }
} ;
int main (){
// ******this is the implementation of Single Inheritance 

        //     dog GS ; 
        //     cout<<"Type of German Shephard is :"<<GS.type<<endl;
        //  GS.tell() ; 
        //  GS.barking() ; 

 // this is the implementation of Multi -Inheritance 

    //  Labra B ;
    //  B.breed() ; 
    //  B.barking() ; 
    //  B.tell() ; 
    //   cout<<"Type of Animal->dog->Labra is :"<<B.type<<endl ;

    //  Labra W ; 
    //  W.breed() ; 

// implementation of Multiple inheritance 
    //  monkey m1 ; 
    //  cout<<m1.color <<endl;
    //   cout<<m1.design <<endl;
    //    m1.dance() ; 
    //    // accessing through parent human 
    //    cout<<m1.Iq <<endl;
    //     cout<<m1.weight <<endl;
    //      cout<<m1.height <<endl;
    //      m1.call() ; 
    //      // accessing through parent animal 
    //       cout<<m1.type <<endl;
    //       m1.tell () ;
// implementation of heirarichal  inheritance 
            // Similiar like the single inheritance 
        
    // bandar b ; 
    //  cout<<b.value <<endl;
    //  b.name() ;
    //  b.dance() ; 
    //  b.call() ; 
    //  b.tell() ; 



// implementation of hybrid - hierarichal inheritance 
        // combination of herarichal inheritance with any of the above inheritance 



 //******* INHERITANCE ABIGUITY 
//  (if two classes have same functions with same name and accesssing these properties by object is done by using socpe resolution operator (::))
         // format (object dot class_ka_name(scope resolution operator ) function_ka_name) like h1.human::call() ;


    c object1  ; 
    object1.A::call() ; 


     cout<<"This is Types of Inheritance in OOPS\n" ;
    return 0 ; 
}