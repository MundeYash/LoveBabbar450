#include<bits/stdc++.h>
using namespace std ; 
// output 
void output (vector <int > &a , int n ){
    for (int i=0 ;i<n ;i++){
        cout<<a[i]<< " " ;
    }
    cout<<endl;
}
// input 
void input (vector <int > &a , int n ){
    for (int i=0 ;i<n ;i++){
         cin>> a[i] ;
    }

}

// checking an array is sorted and rotated (similiar concept like Binary Search  but slight different )
bool CheckSortedRotated (vector <int> &a , int n ){
    // Concept : If more than one pair exits where next value of array is smaller than its previous value , than it is not a sorted rotated array 
int count =0 ;
    for (int i=1 ;i<n ;i++){
    if (a[i ]<a[i-1]){
        count ++ ;

    }
    }

    // edge case for for last and first value comparison 
    if (a[n-1]> a[0]){
        count ++ ;
    }

    // checking condition for returning answer 
    if (count<=1 ){
        return true ;
    }
    return false ;
}
int main (){
    int n ;
    cin>> n ;
    vector<int> a (n) ;
    input(a,n);
    output(a,n) ;
    cout<<endl;
  
  if (CheckSortedRotated(a,n)){
    cout<<"True It is sorted rotated "<<endl; 
  }
else{
    cout<<"Not Sorted Rotated ";
}

  //5 1 2 3 4 5
    
    return 0 ;
}