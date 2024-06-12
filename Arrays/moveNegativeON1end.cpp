#include <iostream>
#include <vector>
using namespace std;
// Move All the negative numbers to one side of the array(LEFT Side of the array )

void moveNegativeOnEnd1(vector<int> &arr, int n)
// Variation1 : without maintaining the order of the elements
{
    // Method 1 : Using any sorting algo 

    // Method 2 : 
    // two pointers approach/ Dutch National Flag Algo  , time : O(n) , space : O(1) 

    int s = 0, e = n - 1;

    while (s <= e)
    {
        if (arr[s] > 0 and arr[e] < 0)
        {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
        else if (arr[s] <= 0)
            s++;
        else if (arr[e] >= 0)
            e--;

        else
        {
            s++;
            e--;
        }
    }

    return;
}

// variation 2 : with Properly maintaining the order of the matrix ;
void moveNegativeOn1End2(vector<int> &arr, int n)
{

    // concept : usign an extra array, teim 
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        if (val < 0)
        {

            ans.push_back(val);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        if (val >= 0)
        {

            ans.push_back(val);
        }
    }

    // copy the elements  from the ans to arr
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i]; 
    }

    return;
}
void printAray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {-2, 3, 1, 3, -44, -90, -100};
    int n = arr.size();
    printAray(arr, n);
    moveNegativeOnEnd1(arr , n );
    printAray(arr, n);

    // with properly maintianing the order of the array
    moveNegativeOn1End2(arr, n);
    printAray(arr, n);

    return 0;
}
/*

Links : https://www.geeksforgeeks.org/problems/arranging-the-array1131/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article (done);
https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1(done)
leetcode : -
*/