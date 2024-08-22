#include<bits/stdc++.h>
using namespace std ; 
// Proogram to make a simple Calculator 

int main (){
    // take two number and Perform some operations on in via calculator making 
    // int a  , b ; 
    // cout<<"Enter two numbers "<<endl; 
    // cin>> a>> b ; 
    // char operation ; 
    // cout<<"Enter the Operation from + , - , *, / , % " <<endl;
    // cin>>operation; 

    // // using the Switch case 
    // switch (operation){

    //     case '+' :{
    //         cout<<"Addition value is :";
    //         cout<<(a+b)<<endl;
    //         break;

    //     }
    //     case '-' :{
    //         cout<<"Subtraction value is :";
    //         cout<<(a-b)<<endl;
    //         break;
    //     }
    //     case '*' :{
    //         cout<<"Multiplication value is :";
    //         cout<<(a*b)<<endl;
    //         break;
    //     }
    //     case '/' :{
    //         cout<<"Division value is :";
    //         cout<<(a/b)<<endl;
    //         break;
    //     }
    //     case '%' :{
    //         cout<<"Modulous value is :";
    //         cout<<(a%b)<<endl;
    //         break;
    //     }
    //     default: cout<<"Enter Correct Operation";
    // }

    // Homework Question to print the number of notes of 100 , 50 , 20 , 10 ruppees for an amount 
    int amount ,  hundred , fifty  , ten , twenty , one ; 
    cout<<"Enter your amount " ; 
    cin>> amount ; 

    
     // this is Homework question for finding the number of notes 
     
     switch(1){
        case  1 : // for hundred ruppee notes 
        hundred = amount / 100 ; 
        amount = amount- (hundred*100) ;
         
        
        cout<<"Hundred Ruppees notes required is :"<<hundred<<endl;

        case  2 : // for fifty ruppee notes 
        fifty = amount / 50 ; 
        amount = amount- (fifty*50) ;
          
        cout<<"Ffity Ruppees notes required is :"<<fifty<<endl;
        case  3 : // for twenty ruppee notes 
        twenty = amount / 20 ; 
        amount = amount- (twenty*20) ;
          
        cout<<"twenty Ruppees notes required is :"<<twenty<<endl;
        case  4 : // for ten ruppee notes 
        ten = amount / 10 ; 
        amount = amount- (ten*10);
          
        cout<<"ten Ruppees notes required is :"<<ten<<endl;

        case  5 : // for one ruppee notes 
        one = amount / 1 ; 
        amount = amount- (one*1);
         
        cout<<"one Ruppees notes required is :"<<one<<endl;

     }
    return 0 ; 
}