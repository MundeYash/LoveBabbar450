#include<bits/stdc++.h>
#include<vector>
using namespace std ;
// input for the vector 
void input (vector<int> &a , int n ){
    for (int i=0;i<n ;i++){
        cin>> a[i] ;
    }
}

// output of vector elements 
void output (vector<int>&a , int n ){
    for (int i=0 ;i<n ;i++){
        cout<<a[i] << " ";
    }
    cout<<endl;
}

// Function for adding two arrays and returing the ans in arrays 
vector<int> add2Arrays (vector<int> &a , int n  ,vector<int> &b , int m ){

    // Concept : TWO POINTERS 
    // Case 1 : Both have equal elements 
        //  case a: equal elements  with carry exists
        // case b : equal elements withour carry exists  

        int i=n-1, j=m-1  ;// sum is calculated from the last 
        int  carry =0; 
        vector<int> ans ;
        while (i>=0 and j>=0){
            int value1 = a[i] ;
            int value2 = b[j];
            // sum value 
            int sum = value1 + value2 + carry ; 


            // carry value (via modulous )
            carry  = sum/ 10 ; 
             


            // actual value (which is to stored in the array )
           sum = sum % 10 ; 
            ans.push_back(sum);
            i-- ; 
            j-- ;

        }
    // Case 2: Unequal number of elements (in array one of the array )

         // (suppose in I st array )
         while (i>=0  ){
            int value1 = a[i]  ; 
            int sum = value1 + carry ;
             carry  = sum /10 ; 
             sum= sum %10 ;
           
            ans.push_back(sum ) ;
            i-- ;

         }
         // (suppose in II nd  array )
         while (j>=0  ){
            int value2 = b[j] ; 
            int sum = value2 + carry ; 
             carry = sum /10 ;
             sum= sum % 10 ; 
           
            ans.push_back(sum) ;
            j-- ;

         }
    // Case 3: Where Carry is remaining (to added at the starting of ans array )
    while (carry!= 0 ){
        int sum =carry; 
        carry = sum /10 ;
        sum = sum %10 ;
        ans.push_back(sum) ;

    }

    // reverse the answer before returning the answer 
    reverse(ans.begin() , ans.end() ) ;
    return ans ;
         

}
int  main (){
    int n , m; 
    cin>> n >> m  ; 
    vector<int> a (n) ;
    vector<int> b (m) ;
    input(a,n) ;
    input(b,m ) ;
    // output(a,n) ;
    cout<<endl;
    // output(b,m);
cout<<endl;
    vector<int> sum ;
    sum= add2Arrays(a,n,b,m); //4 1 1 2 3 4 6
    int s = sum.size( );

    cout<<"The Sum of the two Arrays :";
    output(sum, s);
    return 0 ;
}