#include <bits/stdc++.h>
using namespace std;
// iterative approach
// time complexity : O(exponenetial 2^n)  , space : O(n)
int NthfibonacciIterativeApproach (int n){
    if (n==0 || n==1 ) return n ; 
    int a=0 ,b =1 ; 
    for (int i=2 ;i<=n ;i++){
        
        

    }
}


// Recursive approach , time : Exponential , space : O(n) -> for n function calls (recursive calls stack space )

int NthFibonacci(int n)
{ // base case
    if (n == 0 || n == 1)
        return n;
    // recursive case / recurene relation
    return NthFibonacci(n - 1) + NthFibonacci(n - 2);
}
int main()
{
    cout << "The Nth fibonacci number  is : " << NthFibonacci(10) << endl;
    return 0;
}