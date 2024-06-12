#include <iostream>
#include <vector>
using namespace std;
// Reverse the array
void reverseArray(vector<int> &arr, int n)
{
    // two pointer approach

    int s = 0, e = n - 1;
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void printAray(vector<int> arr, int n)
{
    for (int i = 0 ; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {2, 3, 1, 3, 44, 90, 100};
    int n = arr.size();
    printAray(arr, n);
    reverseArray(arr, n);
    printAray(arr, n);

    return 0;
}