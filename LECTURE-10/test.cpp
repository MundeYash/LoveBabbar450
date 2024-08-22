#include<iostream>
using namespace std ;
// swap the alternative elements in array 
void swapAlter (int a[] , int n ){
    int start = 0 , end = 1 ; 
    while (start< n and end <n ){
        swap(a[start] , a[end]) ; 
        start += 2 ; 
        end += 2 ; 
    }
}
// Reverse the elements of array 
void Reverse_array (int a[] , int n ){
    int start = 0 , end = n-1 ; 
    while (start <= end ){
        swap(a[start] , a[end] ) ; 
        start ++ ; 
        end -- ; 
    }
} 
// linear search in array 
 int liner_search (int a[] , int n , int key ){
    for (int i=0 ;i< n ;i++){
        if (a[i]== key ){
            return i ; 
        }
    }
     return -1 ;
 }
 // Sum of array elements 
 int sum_array(int a[] , int n ){
    int sum =0 ; 
    for (int i=0 ;i<n ;i++){
sum += a[i] ; 
    }
     return sum ; 
 }
 // print the array elements 
 void print_array (int a[]  , int n ){
    for (int i =0 ;i<n ;i++){
        cout<<a[i]<< " "; 
    }
     cout<<endl;
 }
int main(){
    int a[] = {4,3,3,5 ,10,90 } ; 
    int n = sizeof (a)/ sizeof(int ) ; 
    print_array(a,n) ; 
    // int key ; 
    // cin>> key ; 
    //   cout<<"The sum of given array elements is :"<<sum_array(a,n) <<endl; 
    //  if (liner_search(a,n,key)== -1 ){
    //      cout<<"key is not present \n" ; 
        
    //  }
    //  else {
    //    cout<<"Key is present at :"<<liner_search(a,n,key)<<endl ; 
    //  }

 Reverse_array(a,n) ; 
 print_array(a,n ) ; 
  swapAlter(a,n) ; 
  print_array(a,n) ; 

     cout<<"This is lecture no - 10 of Code help \n ARRAYS QUESTIONS\n" ; 
    return 0 ; 
}