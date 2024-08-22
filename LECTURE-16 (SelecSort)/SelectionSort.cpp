#include <iostream> 
using namespace std ; 
// Selection Sort Algorithm time complexity best - o(n*n) , Worst case o(n*n)
  void SelectionSort(int a[] , int n ){
    for (int i=0 ;i< n-1 ;i++){//  n-1 because last element will automatically allocated on their position 
       int minIndex = i ; // assuming starting index value is minimum 
        for (int j= i+1 ; j<n ;j++){
            if (a[j] <a [minIndex]){
                minIndex = j ; // update the minIndex element 
            }
        }
        swap (a[i] , a[minIndex]) ; // swaping the values 
    }
 }
 void arraY_output(int a[] , int n){
    for (int i=0 ;i< n ;i++){
        cout<<a[i] <<" " ; 
         
    }
     cout<<endl;
 }
 void input_array(int a[] , int n ){
    for (int i=0  ; i< n ;i++){
        cin>>a[i] ; 
    }
 }
int main (){
    int a[1000] ; 
    int n ; 
    cin>> n  ; 
    input_array(a,n) ; 
    arraY_output(a,n) ; 
    SelectionSort(a,n) ; 
    arraY_output(a,n) ;


     cout<<"\n This is Selection Sort Algorithm \n" ; 
    return 0 ; 
}