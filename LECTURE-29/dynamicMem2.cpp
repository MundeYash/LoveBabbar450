#include<iostream>
using namespace std  ; 

//Dynamic Memory and Arrays 


void input(int **a  , int n , int m ){
    for (int i=0 ;i<n ;i++){
        for (int j=0;j<m ;j++){
            cin>>a[i][j] ;
        }
    }

}

void output (int **a , int n , int m ){
    for (int i =0 ;i<n ;i++){
        for (int j=0 ; j<m ;j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }

}
int main(){
    // statically 2d array creation 
    int a[100] [100] ; // 

    // dynamically 2d array creation 
    int col = 5 ;
    int **a1 =   new int* [col] ;//col is number of columns 


    // taking n and m from user and create a 2d array dynamically 
    int n  , m ; 
    cin>> n >> m ; 
    int** arr = new int* [n] ;// n is number of rows

    for (int i=0 ;i<m ;i++){// m is the number of columns 
        // for every arr[i] pointer create 1 d array dynamically 
        arr[i]= new int [m] ;
    } 
        input(arr,n ,m ) ; 
        output(arr,n ,m ) ;


        // Mannually deleting the memory 

        for (int i=0 ;i<n ;i++){
            delete[] arr[i] ; // deleting all the colums of every row 
        }


        delete[] arr;// deleting the row array 

    

    return 0 ;
}