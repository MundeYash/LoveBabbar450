#include<iostream>
using namespace std ; 



// function for finding the length of the string 
int lengthString(char ch[] ){
    int count = 0; 
    for (int i=0 ;ch[i]!='\0' ;i++){
        count ++ ;
    }
    return count ;
}


// function for finding reverse of a string 
//I/p -> babbar , o/p -> rabbab 
void reverse(char ch[] ){
    int n = lengthString(ch)  ;
    //Two pointers approach 
    int s =0 , e = n-1 ;
    while (s<=e ){
        swap(ch[s++] , ch[e--]);
    }
}


// function for checking whether a string is palindrome or not 
bool checkPalindrome (char ch[]){
    int n = lengthString(ch);
    int s =0 , e = n-1 ;
    while (s<=e){
        if (ch[s] != ch[e]){
            return false ; 
        }
        s++ ;
        e-- ;

    }
    return true ;
}
int main (){
    char ch[10] = {"goodboy"};
    cout<<"The length of given string / character array is :"<<lengthString(ch)<<endl;

    cout<<"Before :"<<ch<<endl;
    reverse(ch);
    cout<<"After :"<<ch<<endl;
 char name[10] = "naman";
    if (checkPalindrome(name)){
        cout<<" Yes String is Palindrome "<<endl;
    }
    else {
        cout<<"Not a palindrome string ";
    }
}