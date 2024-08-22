#include <bits/stdc++.h>
using namespace std;
// Insertion Sort Algorithm :(at every iteration we take a hand pick card and place it to thier right position )
// time : O(N^2) , space : iterative->O(1) , recursive :O(n)
void insertionSortIterative (vector<int> &a, int n)
{

   for (int i=1 ;i<n ;i++){
    int hpc = i ; 
    for (int j = i-1 ; j>=0 ;j-- ){
        if (a[j]>a[hpc]){// means unsorted card h (means peeche wali value smaller h )

            // shifting of all the elements 
            a[j+1] = a[j] ;


        }
        else {
            // means already sorted part h 
            break ;
            }
        }

        swap(a[hpc] , a[i]) ;
   }
}
void insertionSortRecursive (vector<int> &a, int n)
{
    // arranging every i-th card at its right location 
    //Base case 
    if(n==0|| n==1 ) return ; // means no need to sort the array 

    // work (for aleast one case )

    int hpc = 1 ; 
    for (int j= hpc -1 ; j>=0 ;j--){

        if (a[j]> a[hpc ]){
            // shifting of all the elements to the right 
            a[j+1] = a[j] ;
        }

    }
    swap(a[1] , a[hpc]);

    
    // recursive case / recursive relation 

}


// other variation 
void variation2(vector<int>&a , int n){
    // base case 
    if (n==0 ||n==1){
        return ;// means already sorted array 
    }

    // work 
    for (int j=0 ;j<n-1 ; j++){
        if (a[j]>a[j+1]){
            swap(a[j] , a[j+1]) ; 
        }
    }
    // recursive case / relation 
    variation2(a, n-1);//At every recursive call the size gets reduced only unsorted array will be considered 

}
void print(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> a = {100, 1, 11, 10, 19, 15, 10};
    int n = a.size();
    print(a, n);
    // bubbleSort(a, n);
    // RecBubbleSort(a, n, 0);
    variation2(a,n) ;
    print(a, n);
    return 0;
}