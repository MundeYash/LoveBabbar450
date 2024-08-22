// INTRODUCTION TO THE 2D ARRAY : In memory actually the 2D array is store in the form of single array with size = (n*m) and index ranging from the (0 to (m*n)-1 )
/*Formula for finding the indexes of value store in the 2D array 
     Formula = (c* i + j ); where c-> number of colums in the 2d array ,
                                i -> ith row number number 
                                j-> jth column number 
                                
*/

#include <bits/stdc++.h>
using namespace std;

// function for taking the input of the 2 d array
void TwodArrayoUTput(int a[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// COLUMN WISE INPUT FOR 2D ARRAY 
//
void colwiseArrayINput(int a[][100], int n, int m)
{
   for (int j=0 ;j<m ;j++){
    for (int i=0 ;i<n ;i++){
        cin>>a[i][j] ;
    }
   }
}

void rowWiseinput(int a[][100], int n, int m){
     // taking of input of 2 D array from the user
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
    }
}

int main()
{

    // declaration of 2d array (datatype arrayname[noOfRows ][noOfColumns])

    int arr[100][100];
    int b [][100] ={{1,2,3,11,34} , {13,3,5,15,11}};
    TwodArrayoUTput(b,2,5);
    // rowWiseinput(arr,4,2);
    colwiseArrayINput(arr,4,2);


   
    // declaration of 2d array

    TwodArrayoUTput(arr, 4, 2);

    return 0;
}