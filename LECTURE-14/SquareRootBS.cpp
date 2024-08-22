#include <iostream>
using namespace std;

// Brute force approach for finding the square root of number
int findSroot(int n) // T: root (n)
{
    for (int i = 1; (i * i) <= n; i++)
    {
        if (i * i == n)
        {
            return i;
        }
    }
    return -1;
}
// time Complexity - o(log n )

// function for getting more precised value
double morePrecised(int n, int precisionSize, int tempSol)
{

    double ans = tempSol;
    double factor = 1;
    for (int i = 0; i < precisionSize; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}
long long int FindSquareRoot(int n)
{
    // binary search implementation
    int s = 0, e = n, ans = -1;

    while (s <= e)
    {

        long long int mid = s + (e - s) / 2;
        long long int square_value = mid * mid;
        // ans = mid;
        // if we get value equal to number
        if (square_value == n)
        {
            return ans;
        }

        //   if we get value greater than number
        else if (square_value > n)
        {
            ans = mid;
            e = mid - 1;
        }
        // if we get value less than number
        else
        {
            s = mid + 1;
        }
    }
    return ans; // this gives the nearest value of square root for given number
}
int main()
{
    int n;
    cin >> n;
    int tempsol = FindSquareRoot(n);
    cout<<"The Square of "<<n<<" is : "<< FindSquareRoot(n) <<endl;
    cout<<"More Precised Square root value is : "<<morePrecised(n,5,tempsol) ;

    cout<<"\nProgram to Find out the Square Root of number using ->Binary Search <-\n";

    // this is brute force approach
    // cout << findSroot(29) << endl;
    return 0;
}