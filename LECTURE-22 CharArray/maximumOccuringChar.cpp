#include<iostream>
using namespace std  ; 

void print (int a[] ){
    for (int i=0 ;i<26 ;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
// function for finding the maximum value of distinct charcter in the string 
char maxiOccurence(string s ){
   
    // step 1  : Creating the array all characters (A-z) and storing their frequencies 
     int arr[26] ={0};
    for (int i=0 ;i<s.length() ;i++){
        char value = s[i];
        int index = 0 ;

        // finding the index  of selected character

        if (value>='a' and value<='z'){
            //lower case character 
            index = value -'a';

        }
        else if (value>='A' and value<='Z'){
            // Upper case character 
            index = value -'A';
        }
        arr[index]++ ;// increasing the value 

    }

    // finding the maximum occurence 
    int ans=-1 , maxi =-1 ;
    for (int i=0 ;i<26 ;i++){
        if (arr[i]>maxi){
            maxi = arr[i] ;
            ans =i ;
        }

    }
    // maxi denotes the occurence of character , while ans denotes the index 
     print(arr);
    char finalvalue= ans +'a';
    cout<<finalvalue<<" "<<maxi<<endl;
    return (finalvalue);
   

}
int main (){
    string s = "bhartashree";
    cout<< maxiOccurence(s);

    return 0 ;
}