//Find the previous smaller element smaller element on left 
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
vector<int> prevSmaller1(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        int value = arr[i];
        int samller = -1;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < value)
            {
                samller = arr[j];
            }
        }
        ans[i] = samller;
    }
    return ans;
}

// OPTTMISED APPROACH -time  : O(n), space : O(n-> due to stack )

// function for finding the previous smaller  Element

vector<int> prevSmaller(vector<int> &arr, int n)
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
        else if (!s.empty() && s.top() < curr)
        {
            ans[i] = s.top();
        }
        else
        {
            //
            while (!s.empty() and s.top() >= curr)
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

    vector<int> ans = prevSmaller1(arr, n);
    printArray(ans, n);

    // vector<int> ans = prevSmaller(arr, n);
    // printArray(ans, n);

    cout << "AFTER the  previous smaller  element finded " << endl;

    return 0;
}


/*
Links : 
gfg ; https://www.geeksforgeeks.org/problems/smaller-on-left20360700/1          (rem)
code studio : 
interview bit ; 
leetcode ; 


 // other similiar Question 
 https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1        (done)
*/