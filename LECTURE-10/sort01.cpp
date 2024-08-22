#include <iostream>
using namespace std;
// sort the 0 and 1 array

// Method 1 : Using Two pointer (start , end , i )  / Dutch National Flag Algorithm 

void sortZeroOne(int arr[], int n)
{

    int start = 0, end = n - 1, i = 0;

    while (start <= end)
    {
        if (arr[i] == 0)
        {
            swap(arr[start], arr[i]);
            start++;
            i++;
        }

        else
        {
            // arr[i]==1
            swap(arr[end], arr[i]);
            end--;
        }
    }
    return;
}
// Method 2
void sort01(int a[], int n)
{
    int s = 0, e = n - 1;
    while (s < e)
    {

        if (a[s] == 1 and a[e] == 0)
        {
            swap(a[s], a[e]);
            s++;
            e--;
        }
        else if (a[s] == 0)
        {
            s++;
        }
        else
        {
            e--;
        }
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //7 1 0 1 0 1 1 0
    print(a, n);
    cout<<"After Sorting : "<<endl;
    sort01(a, n);
    // sortZeroOne(a, n);
    print(a, n);

    return 0;
}