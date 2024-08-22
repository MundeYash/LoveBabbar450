#include <bits/stdc++.h>
using namespace std;
// Count the number of prime numbers which is less than  n :




bool checkPrimes(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Brute force : function for counting the number of primes, time =O(N^2)
vector<int> countPrime1(int n)
{
    vector<int> ans;
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (checkPrimes(i))
        {
            ans.push_back(i);
            // count ++ ;
        }
    }
    return ans;
}



vector<int>countPrimes2 (int n ){
    // OPtimised Approach : PrimeSieves  (sieves of ) , time =O(log (log n ))
    vector<bool >prime (n + 1, true ) ;// assume all numbers are prime numbers 
    prime[0] = prime[1] = false ;/// 0 and 1 are non primes 

     int count =  0 ; 
     vector<int>ans ;
     for (int i=2 ;i<n ;i++){//less than n prime numbers 
         if (prime[i]){
            count ++ ; 

            // checking condition for its multiples 
            for (int j=(2*i) ; j<n ;j = j+ i ){
                prime[j] =false;
            }
         }

     }

     for (int i=0 ;i<n ;i++){
        if (prime[i] == true ){
            ans.push_back(i) ;
        }
     }

    //  return count ; or return ans.size();
    return ans ; 


}
// function for printing
void print(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans1 = countPrime1(n);
    vector<int> ans2 = countPrimes2(n);
    print(ans1);
    print(ans2);


    cout << "The number of primes is :" << countPrime1(n).size() << endl;
    cout << "The number of primes is :" << countPrimes2(n).size() << endl;
    return 0;
}

/*Similiar Quesiton practice links 
Perfect Square : https://leetcode.com/problems/perfect-squares/description/
Ugly numbers :https://leetcode.com/problems/ugly-number/description/
Ugly Numbers 2 :https://leetcode.com/problems/ugly-number/description/
Happy numbers :https://leetcode.com/problems/ugly-number/description/





GFG


https://practice.geeksforgeeks.org/problems/count-primes-in-range1604/1



*/