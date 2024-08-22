// Very very important question (mostly asked in the interviews )
#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH :time : O(n^2) ,space : O(1)

// helper function for finding the left and right expansion
int leftExpansion(vector<int> arr, int n, int index)
{
    int left = 0;
    for (int i = index - 1; i >= 0; i--)
    {
        if (arr[i] >= arr[index])
        {
            left++;
        }
        else
        {
            break;
        }
    }
    return left;
}

int rightExpansion(vector<int> arr, int n, int index)
{
    int right = 0;
    for (int i = index + 1; i < n; i++)
    {
        if (arr[i] >= arr[index])
        {
            right++;
        }
        else
        {
            break;
        }
    }
    return right;
}
// exploring all the possible rectangles for each bar

int largestArea1(vector<int> arr, int n)
{
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int length = arr[i];

        if (length != 0)
        {

            // step2 : exploring maximum left and right

            // a) left index exploration

            // b) right index exploration
            int left = leftExpansion(arr, n, i);
            int right = rightExpansion(arr, n, i);
            cout << "index :" << i << " " << left << right << endl;
            int width = left + right + 1;

            int area = (length * width);
            if (area > maxArea)
            {
                maxArea = area;
            }
        }
    }
    return maxArea;
}

// OPTIMISED SOLUTION : CONCEPT -> STACKS , TIME :o(N) , space : O(N)
// helper function for finding the next smaller element in indexes form

vector<int> nextsmaller(vector<int> arr, int n)
{
    vector<int> ans(n, -1);
    // stack
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int currValue = arr[i];

        while (st.top() != -1 and arr[st.top()] >= currValue)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

// helper function for finding the previous smaller element
vector<int> previousSamller(vector<int> arr, int n)
{
    vector<int> ans(n, -1);
    // stack
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        int currValue = arr[i];

        while (st.top() != -1 and arr[st.top()] >= currValue)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}
int largestArea2(vector<int> arr, int n)
{
    // concept : previous smaller element and next smaller element
    int maxArea = 0;
    vector<int> nextSmall(n, -1);
    nextSmall = nextsmaller(arr, n);

    vector<int> prevSmall(n, -1);
    prevSmall = previousSamller(arr, n);

    for (int i = 0; i < n; i++)
    {
        int length = arr[i];

        if (nextSmall[i] == -1)
        {
            nextSmall[i] = n;
        }

        int width = (nextSmall[i] - prevSmall[i] - 1);

        int area = (length * width);
        if (area > maxArea)
        {
            maxArea = area;
        }
    }

    return maxArea;
}
void input(vector<int> &heights, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    return;
}

int main()
{
    vector<int> heights = {8, 6, 3, 5, 0, 0, 4, 10, 2, 5}; /// 8 ,6, 3, 5 ,0, 0 ,4 ,10 ,2 ,5/1, 0, 1, 2, 2, 2, 2, 1, 0, 2,
    int n = heights.size();

    // int n;
    // cin >> n;
    // vector<int> heights(n);
    // input(heights, n);

    cout << "The maximum area possible of largest rectangle in the bar graph  / histogram is :" << largestArea1(heights, n) << endl;
    cout << "The maximum area possible of largest rectangle in the bar graph  / histogram is :" << largestArea2(heights, n) << endl;
    return 0;
}

/*
Links :
gfg : https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1       (rem)
codestudio : https://www.codingninjas.com/studio/problems/largest-rectangle-in-a-histogram_1058184       (done)
Leetcode : https://leetcode.com/problems/largest-rectangle-in-histogram/description/             (done)

interview bit  ;

similiar question : https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1      (rem)
https://leetcode.com/problems/asteroid-collision/a  (rem)
*/