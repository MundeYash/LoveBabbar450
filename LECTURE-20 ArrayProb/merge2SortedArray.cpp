#include<iostream>
using namespace std ; 
//Merge two sorted arrays 
 void input (int a[] , int n ){
    for (int i=0 ;i<n ;i++){
        cin>> a[i];
    }
 }

// output 
void output ( int a[] , int n ){
for (int i=0 ;i<(n) ;i++){
    cout<<a[i] <<" ";
}
}

 // function for merging two sorted array 
 int* merge2SortedArrays (int a[] , int n , int  b[] , int m ){
    int*c = new int[n+m] ;

    // Concept : Two pointers approach 
    int i=0 , j=0 , k=0 ; 
    while (i<n and j<m )
{
    if (a[i]<=b[j]){
        c[k++] = a[i++] ;


    }
    else {
        c[k++] = b[j++];
    }
}

// Case 2 some element or numbers left in one of the arrays 
while (i<n){
    c[k++] = a[i++] ;
}
while (j<n ){
    c[k++] = b[j++];
}

 return c;
 }
int main (){
    int n , m ; 
    cin>> n >>m ;
    int *a = new int [n] ;
    int *b = new int[m] ;
    input(a,n);
    input(b,m);

output(a,n) ;
cout<<endl;
output(b,m);
cout<<endl;

cout<<"MergeSorted Array is : ";
    int *c  = merge2SortedArrays(a,n,b,m );

    output(c , (n+m));

    //3 3   1 2 3  2 5 6 
    //1 1 1 1 


    return 0 ;
}