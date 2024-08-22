#include<iostream> 
using namespace std ; 
 void input_array(int a[] , int n ){
    for (int i=0 ;i<n ;i++){
        cin>>a[i] ; 
    }
 }
 bool IsAllocate (int a[] , int n , int m , int mid ){
    int studentCount =1 , pageSum =0 ;

    for (int i=0 ;i<n ;i++){
        if (pageSum + a[i] <= mid ){// checking if page sum value with array element value is less than mid 
            pageSum += a[i] ; 

        }
        else {
             studentCount ++ ; // allocate to next student 
              if (studentCount >m || a[i]> mid ){ // particular selected book ki number page hi greater than mid  
                return false ; 
              }
             pageSum = a[i] ; // next student ko contigious allocate karo 
        }
    } 
    return true ; 
    

 }
 int find_sum (int a[] , int n  ){
    int sum =0 ; 
    for (int i=0 ;i<n ;i++){
sum += a[i] ; 
    }
     return sum ; 
 }
 int Allocate_Books (int a[] , int n , int m   ){
    int s = 0 , e= find_sum(a,n ) ; // for Search Space finding 
    int  ans =-1  , mid  ; 
     while (s<=e){
           mid = s + (e-s) /2  ; 
          if (IsAllocate(a,n,m,mid)){// means if  is  possible solution and  allocation is done 
            ans = mid ;  // store the ans 
            e = mid - 1; // further optimsize it 
          }
           else {// if Allocation is not possible 
                s  = mid + 1; 

           }

     }
      return ans ; 
 }
int main (){
    // int a[] = {5,17,100,11} ; // array of books containing number of pages
     int a[100] ; 
     int n ; 
     cin>>n ; 
      int m ; // number of student for  allocate books
    // cout<<"Enter Number of Students \n" ; 
    cin>> m ; 
     input_array(a,n) ; 
     

    // int n = sizeof (a) / sizeof (int ) ; 
   
     cout<<Allocate_Books(a,n,m) ;  // calling the function 
   
    
     cout<<"\nThis is Book Allocation Problem using Binary Search \n" ; 
    return 0 ; 
}