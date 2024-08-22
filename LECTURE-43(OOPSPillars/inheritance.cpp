#include <bits/stdc++.h>
using namespace std;

// inheritance: accessing data members and functions of one class in other class

class human
{
public:
    int height;
    int weight;
    int age;

    int getAge()
    {
        return this->age;
    }

    void setWeight(int weight)
    {
        this->weight = weight;
    }
};

// public inhertiance example

// format => class (keyword) childClass ka name : (colon operator ) mode (public ) parentClass ka name
class male : private human
{ // male is inherited from the human class
public:
    string color;

    void sleep()
    {
        cout << "Male is sleeping" << endl;
    }
   void show(){
     cout<<this->height<<endl;
     cout<<this->weight<<endl;
     cout<<this->age<<endl;
   }
};
int main()
{
    human indian; // creation of object of human class

    male ramesh; // creation of obeject of male class pulic inherited from the human class ;
    ramesh.color = "black";
    // ramesh.height = 100;
    // ramesh.setWeight(12);
    // cout << ramesh.age << endl;
    // cout << ramesh.weight << endl;
    // cout << ramesh.height << endl;

    cout << ramesh.color << endl;
    ramesh.sleep();

    return 0;
}