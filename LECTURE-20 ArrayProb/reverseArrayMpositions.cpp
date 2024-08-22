#include<iostream>
using namespace std  ; 
// Reversing an array after the 'm' th index 
void mReverse (int a[] , int n , int m  ){
    int s = (m+1 ) , e  = n-1 ;
    while (s<=e ){
        swap(a[s++] , a[e--]) ;

    }
}

// function for input array 
void input (int a[] , int n ){
    for (int i=0 ;i<n ;i++){
        cin>> a[i];
    }
}

// function for ouput array 
void output (int a[] , int n ){
    for (int i=0 ;i<n ;i++){
        cout<< a[i]<<" ";
    }
    cout<<endl;
}
 int main (){
    int n ; 
    cin>> n ; 
    int m =3 ;
    int * a = new int [n] ;
    input(a,n);
    output(a,n) ;
    mReverse(a, n , m ) ;
     cout<<"The array after the m reversal : ";
    output(a,n);

    return 0 ;
}