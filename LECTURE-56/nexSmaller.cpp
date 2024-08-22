
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
vector<int> nextSmaller1(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        int value = arr[i];
        int small = -1;

        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < value)
            {
                small = arr[j];
            }
        }
        ans[i] = small;
    }
    return ans;
}

// OPTTMISED APPROACH -time  : O(n), space : O(n-> due to stack )

// function for finding the next Smaller Element

vector<int> nextSmaller(vector<int> &arr, int n)
{
    // step1 : iterating from rigth to left and
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        arr[i] = s.top();
        s.push(curr);
    }
    return arr;
}
int main()
{
    vector<int> arr = {5, 1, 4, 3, 10};
    int n = arr.size();
    printArray(arr, n);
    vector<int> ans = nextSmaller1(arr, n);
      printArray(ans, n);


    nextSmaller(arr, n);
    printArray(arr, n);
  

    cout << "AFTER the next smaller element finded " << endl;

    return 0;
}

/*

Links :
code studio : https://www.codingninjas.com/studio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM        (done)
gfg: https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article          (done)
leetcode :
interveiw bit :


// similiar questions

https://www.geeksforgeeks.org/problems/help-classmates--141631/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article      (done)
*/