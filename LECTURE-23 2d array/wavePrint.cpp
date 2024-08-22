#include<bits/stdc++.h>
using namespace std ; 

// function for printing the wave 
void printWave (vector<vector<int>>&arr , int n , int m ){

    for (int i=0 ;i<n ;i++ ){

        if (i%2 ==0 ){
                // For Even row Value : print left to right 
                
            
            for (int j=0 ;j<m ;j++ ){
                
                cout<<arr[i][j]<<" ";
            }

        }
        else{
            // For Odd row value : print Right to left (column wise )

            for (int j=m-1 ;j>=0 ;j-- ){
                cout<<arr[i][j]<<" ";
            }

        }
        cout<<endl;



    }


}
// function for printing the array 
void printArray(vector<vector<int>> arr , int n , int m ){
    for (int i=0 ;i<n ;i++ )
    {
        for (int j=0 ;j<m ;j++ ){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main (){
    vector<vector<int> > arr ={{1,2,3} ,  {4,5,6} , {7,8,9}} ; 
    int n = arr.size() ; 
    int m = arr[0].size() ; 
    printArray(arr , n ,m );

    cout<<"WAVE Pattern Printing "<<endl;
    printWave(arr ,n ,m );


    return  0 ;
}

// Links : 