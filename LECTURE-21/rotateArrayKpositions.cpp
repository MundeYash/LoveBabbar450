#include<iostream>
#include<vector>
using namespace std ;

//Concept : MODULOUS (for placing the values at the correct positions )

// input 
void input (vector<int  > &a  , int n ){
    for (int i=0 ;i<n ;i++){
        cin>> a[i] ;
    }
}

//output 
void output (vector<int> &a  ,int n ){
    for (int i=0 ;i<n  ;i++){
        cout<<a[i] <<" ";
    }
    cout<<endl;
}
// rotating the array k postions 

vector<int>  RotateArrayKpositions(vector<int> &a    , int n  , int k){
    // creating a new array for  storing the values 
vector <int >  ans (n) ;
    for (int i=0;i<n;i++){
        // placing the values at the right positions 
        ans [(i+k)% n ] = a[i];
    }
    a = ans ;
     return a  ;


}

int main (){
    int n  , k; 
    cin>> n >> k;
    vector<int> a(n) ;
     input(a,n ) ;
     output(a,n) ;
     RotateArrayKpositions(a,n,k);
     // printing the values after rotating the k positions 
    
     cout<<"The values of the array after rotating the k positions is : ";
     output(a,n );
    

    return  0; 
    // 7 3  1 2 3  4 5 6 7 
}