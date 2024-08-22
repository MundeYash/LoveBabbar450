#include <bits/stdc++.h>
using namespace std;
// Bubble Sort Algorithm :(at every iteration we find the minimum and swap it with the min index value )

void bubbleSort(vector<int> &a, int n)
{
// iterative : time = > O(N^2) , space : O(1)
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = 0; j < n; j++)
        { // AT EVERY iteration the largest element gets fixed with to its position
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void RecBubbleSort(vector<int> &a, int n, int i)
{
    // time : O(n^2 ) , space : O(n)
    // ith round mein ith largest elemenet apni correct location par place hojayga 

    // base case
    if (i == n - 1)
    {
        return;
    }

    // work(one case to be solved )
    for (int j = 0; j < n - i - 1; j++)
    {
        if (a[j] > a[j + 1])
        {
            swap(a[j], a[j + 1]);
        }
    }

    // recursive case
    RecBubbleSort(a, n, i + 1);
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