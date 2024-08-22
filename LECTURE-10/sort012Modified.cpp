// this is important quality question 
#include<iostream>
using namespace std ; 
void sort012(int a[] , int n ){

    // area wise distribution part 
    // zero 0 ka area [ 0 to j ]
    // one 1  ka area [j to i-1 ]
    // two 2  ka area [k+1 to (n-1 )]
    int i =0 , j = 0 , k (n-1 ) ;
    // i to k is unknown area part 
    while (i<=k){
        if (a[i]==0 )
        {
            swap(a[i] , a[j]) ; 
            i++ ; 
            j++ ;

        }
        else if (a[i]==1 ){
            i++ ;

        }
        else {// a[i]==2 
        swap(a[i] , a[k]) ; 
        k-- ;


        }
    }

}
void print (int a[] , int n ){
    for (int i=0 ;i<n ;i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

int main (){
    int n ; 
    int a[]= {0,1,1,1,1,2,0,0,2,1,1};
    // cin>> n ; 
    // int *a = new int [n] ; 
    
    n = sizeof (a)/sizeof (int ) ;
    // for (int i=0 ;i<n ;i++){
    //     cin>>a[i];
    // }
     sort012(a,n) ;
     print(a,n);
    return 0 ; 
}
/*
Links : Leetcode : https://leetcode.com/problems/sort-colors/description/ (done )

*/