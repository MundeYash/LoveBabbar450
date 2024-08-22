
#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// BRUTE FORCE APPROACH  : Time :(N^2)
vector<int> nextGreater1(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        int value = arr[i];
        int greater = -1;

        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] > value)
            {
                greater = arr[j];
            }
        }
        ans[i] = greater;
    }
    return ans;
}

// OPTTMISED APPROACH -time  : O(n), space : O(n-> due to stack )

// function for finding the next greater Element

vector<int> nextGreater(vector<int> &arr, int n)
{
    // step1 : iterating from rigth to left and
    stack<int> s;
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        if (s.empty())
        {
            ans[i] = -1;
        }
        else if (!s.empty() && s.top() > curr)
        {
            ans[i] = s.top();
        }
        else
        {
            //
            while (!s.empty() and s.top() <= curr)
            {
                s.pop();
            }

            if (s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = s.top();
            }
        }
        s.push(curr);
    }
    return ans;
}
int main()
{
    vector<int> arr = {5, 1, 4, 3, 10};
    int n = arr.size();
    printArray(arr, n);
    // vector<int> ans = nextGreater1(arr, n);
    //   printArray(ans, n);

    vector<int> ans = nextGreater(arr, n);
    printArray(ans, n);

    cout << "AFTER the next greater element finded " << endl;

    return 0;
}
/*
Links
gfg : https://www.geeksforgeeks.org/problems/next-greater-element/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article       (done)
    https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article       (done)

*/