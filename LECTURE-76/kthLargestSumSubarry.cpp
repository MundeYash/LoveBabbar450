
#include <bits/stdc++.h>
using namespace std;

// Question : Kt Largest subarray sum : given an array and we need to find the kth largest sum from all the possible subarrays

// approach  1(Brute Force ) : Concept : sorting algo , time (n^2 log (n)):  , space : O(n^2)
int approach1(vector<int> &arr, int n, int k)
{

    // step 1 : store all the sum of the possible subarray in vector
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            ans.push_back(sum);
        }
    }

    // step2 : sort  the vector and kth largest will at n-k index
    sort(ans.begin(), ans.end());

    return ans[ans.size() - k];
}

// approach  2(Optimised  Force ) : Concept : Priority queue approach  , time : O(n^2 log n ) , space : O(k)(space optimised approach )
int approach2(vector<int> arr, int n, int k)
{

    // Use kth largest array element finding approach here

    priority_queue<int, vector<int>, greater<int>> pq;

    // step 1 : insert the first k sum to the min heap

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {

            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                // if current sum is larger
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    // step 3 : k th largest sum will be present at the top of the min heap
    return pq.top();
}

int main()
{
    vector<int> arr = {5, 4, 7, 6};
    int n = arr.size();
    int k = 3;

    cout << "The k th largest sum of the subarray of the given array is : " << approach1(arr, n, k) << endl;
    cout << "The k th largest sum of the subarray of the given array is : " << approach2(arr, n, k) << endl;
    return 0;
}
/*
Code Studio :https://www.codingninjas.com/studio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0 (done)
gfg :https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1   (done )
interview Bit ;
Leetcode :
*/