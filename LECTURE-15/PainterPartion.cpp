#include <bits/stdc++.h>
using namespace std;
// Painter's Partition Problem (Binary Search form ) // Problem No -122 code studio
bool isPainted(vector<int> &a, int n, int mid, int k)
{
    int paintSum = 0, paintCount = 1;
    for (int i = 0; i < n; i++)
    {
        if (paintSum + a[i] <= mid)
        {
            paintSum += a[i];
        }
        else
        {
            paintCount++;
            if (paintCount > k || a[i] > mid)
            {
                return false;
            }
            paintSum = a[i];
        }
    }
    return true;
}

int Sum(vector<int> a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}
void input(vector<int> &a, int n)
{

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << endl;
}
void output(vector<int> a, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int findLargestMinDistance(vector<int> &a, int n, int k)
{
    int s = 0, e = Sum(a, n), ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPainted(a, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    
    int n , k ; 
    cin>> n >> k ; 
    vector<int> a(n);
    for ( int i=0 ;i<n ;i++){
        cin>>a[i];
    }
    // int n = 4, k = 2;
    // cin>>n>>k ;
    // boards.push_back(10);
    // boards.push_back(20);
    // boards.push_back(30);
    // boards.push_back(40);
    // input(boards , n) ;
    // output(boards , n ) ;

// printing 
for(int i=0 ;i<n ;i++){
    cout<<a[i]<<" ";
}
cout<<endl;
    cout << findLargestMinDistance(a, n, k);

    cout << "\nThis is Painter's Partition Problem  using Binary Search \n";
    return 0;
}