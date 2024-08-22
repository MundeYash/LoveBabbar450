#include <bits/stdc++.h>
#include <algorithm> // header file for the algorithm STL
using namespace std;
// this header aims for using the mostly used alog in short time
/*
sort () ,reverse(),count() , *min_element() , *max_element() , binary_search()
, accumulate () , find() , lower_bound() , upper_bound()

*/

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(13);
    v.push_back(13);
    v.push_back(-9);
    v.push_back(326);
    int x = 32;
    // to find a particular element
    auto it = find(v.begin(), v.end(), x); // it gives the iterator of occurence of x
    cout << *it << endl;
    // 2 . Find using the Binary Search (The order of element should be sorted for implementing the binary search algorithm )
    cout << "Binary search algo " << binary_search(v.begin(), v.end(), x) << endl;

    // To the lower bound
    cout << "Lower Bound :" << lower_bound(v.begin(), v.end(), 13) - v.begin() << endl;

    // to get the upper of element
    cout << "Upper Bound :" << upper_bound(v.begin(), v.end(), 13) - v.begin() << endl;

    // to maximum element
    // to get maximum number between two elements
    cout << max(2, 51) << endl;
    cout << "Maximum element is : " << *max_element(v.begin(), v.end()) << endl;

    // to minimum  element
    // to get minimum  number between two elements
    cout << min(2, 51) << endl;
    cout << "Minimum  element is : " << *min_element(v.begin(), v.end()) << endl;

    // To reverse the element
    reverse(v.begin(), v.end());
    string v1 = "goodZilla";
    reverse(v1.begin(), v1.end());
    cout << v1 << endl;

    // to ratote the value
    rotate(v.begin(),v.begin()+1 , v.end());

    // to sort the values (based on the INTRO SORT (combination of three algo qucik sort , heap sort , insertion sort ))
     sort (v.begin() , v.end());
    // printing
    for (auto ch : v)
    {
        cout << ch << " ";
    }

    return 0;
}