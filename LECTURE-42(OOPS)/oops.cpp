 #include <bits/stdc++.h>
// #include"hero.cpp"// using the class created in the hero.cpp file
using namespace std;
// Object_Orineted Programming  in c++

// concept of  Classes->access modifier
//    (public -> can be access anywhere  ,
//  private ->can not  be  accessed   and protected-> can be only accessed inside the class  ) , by default the class is protected

class Hero
{
public:
    // some of properties of class
    char *name;
    int health;
    char level;
    float f;

    static int timeToComplete ; // this is static member of the class 
    // default constructor (mannually creation )
    Hero() //// DEFAULT CONSTRUCTOR ;
    {
        cout << "Inside the default constructor " << endl;
        cout << "Address of this pointer is " << this << endl;
        name = new char[100];
    }

    // Parameterised Constructor
    Hero(int health);
    // { // here input parameter and data member has same name
    //     cout << "Address of this pointer is " << this << endl;

    //     health = health; // input health mein health daal diya gaya h
    //     (*this).health = health;
    // }

    // // multiple parameterised constructor

    // // copy constructor (created by the user)

    Hero(Hero &temp)
    { // by reference is passed to avoid the loop case
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name); // copy the elements (created an entirely new array )
        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print()
    {
        cout << "The level is :" << level << endl;
        cout << "The health  is :" << health << endl;
        cout << "Name is : " << name << endl;
    }
    char getLevel()
    {
        return level;
    }
    int getHealth()
    {
        return health;
    }

    void setHealth(int health)
    {
        this->health = health;
    }
    void setLevel(char level)
    {
        this->level = level;
    }
    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    // creation of static function 
    static void random(){
        cout<<"the static member function is :"<<timeToComplete<<endl;
    }

    // destructor creation
    ~Hero()
    {
        cout << "Destructor Called " << endl;
        cout << "End of the created constructor " << endl;
    }
};


// intializing  the static member of the class 
int Hero::timeToComplete = 65 ;
int main()
{
    cout << "HI" << endl;

    // creation of object

    // // Static allocation (created object statically )
    // Hero mario(45); // it is an object of class named hero

    // cout << "The size of hero : ->" << sizeof(mario) << endl;
    // mario.level = 'a';
    // mario.health = 45;
    // cout << "The health is :" << mario.health << endl;
    // cout << "The level is :" << mario.level << endl;

    // // calling function for created class
    // // mario.print();
    // // GETTER:
    // cout << mario.getHealth() << endl;
    // cout << mario.getLevel() << endl;

    // // SETTER :
    // mario.setHealth(199);
    // mario.setLevel('H');

    // mario.print();

    // // dynamic allocation
    // Hero *h1 = new Hero; //(dynamically created hero which points to h1 pointer )
    //                      // sett values manually
    // (*h1).level = 'F';
    // (*h1).health = 9328;
    // cout << "The level of h1 " << (*h1).level << endl;
    // cout << "The health  of h1 " << (*h1).health << endl;

    // // other way of doing the same thing (accessing the dynamically created object using arrow (-> ) opertor )
    // h1->health = 423;
    // h1->level = 'g';
    // cout << "The new level of h1 " << h1->level << endl;
    // cout << "The new health of h1 " << h1->health << endl;

    // cout << "Print  via dereference operator " << endl;
    // (*h1).print();

    // cout << "Print via -> arrow operator " << endl;
    // h1->print();

    // // This Pointer
    // cout << "The address of mario is " << &mario << endl;

    // // copy constructor
    // Hero SuperM (mario); // here mario object is copied to the  SuperM object

    // // user defined copy constructor creation
    // Hero paul (mario);

    // deep copy and shallow copy
    Hero hero1;
    // hero1.setHealth(1000);
    // hero1.setHealth('k');
    // char name[100] = "babbaar";
    // hero1.setName(name);
    // hero1.print();

    // // use default copy constructor and create new object
    // // Hero hero2 = hero1;
    // // hero2.print();
    // Hero hero2;
    // hero2.setHealth(3232);
    // hero2.setLevel('d');
    // char *nam = "yash";
    // hero2.setName(nam);

    // // now changes in the name in hero1 ;
    // hero1.name[1] = 'g';
    // hero1.print();
    // hero2.print();

    // // Copy Assignment Operator

    // hero1.print();
    // hero2.print();
    // hero1 = hero2;
    // cout << "This is after the copy assignment operator Used value " << endl;
    // hero1.print();
    // hero2.print();
    Hero *h2 = new Hero; // this is dynamically created object (here we have to manually called the destructor )
    delete h2; 

    // printing the value of static data member of the class 
    // cout<<"The value of timeToComplete static data member of the class is : "<<Hero::timeToComplete<<endl;


    // static member function 
    Hero::random();



    cout << "BYE" << endl;
}