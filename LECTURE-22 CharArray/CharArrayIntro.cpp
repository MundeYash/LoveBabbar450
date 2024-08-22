#include <iostream>
using namespace std;

// Introduction to the STRINGS and CHARACTER ARRAY

int main()
{
    char ch[39];
    cout << "Enter input ";
    cin >> ch;

    // if we mannualy add the null character any index 
    ch[3]='\0' ; // null character added 
    cout << "OUPUT:" << ch;

    // for taking the input in character array , (cin)command ignores the white spaces , enter button , tab button 


    

    return 0;
}