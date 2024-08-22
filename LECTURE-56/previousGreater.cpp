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
vector<int> prevGreater1(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        int value = arr[i];
        int greater = -1;

        for (int j = 0; j < i; j++)
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

vector<int> prevGreater(vector<int> &arr, int n)
{
    // step1 : iterating from left to right
    stack<int> s;
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
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

    vector<int> ans = prevGreater1(arr, n);
    printArray(ans, n);

    // vector<int> ans = prevGreater(arr, n);
    // printArray(ans, n);

    cout << "AFTER the  previous greater element finded " << endl;

    return 0;
}