#include <iostream>
#include <vector>

using namespace std;
void print_value(vector<int> &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
// Optimised approach : Using the Binary Search : T->O(log n ) ,space : O(1)
int findPeakElement(vector<int> &arr)
{

    int n = arr.size();
    int s = 0, e = n - 1;
    while (s < e)
    { // just to avoid repeat case
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }

        // case 1 for increasing value
    }
    return s; // at this point both points at the same index start and end
}
int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(10);
    v.push_back(5);

    v.push_back(2);
    print_value(v);
    cout << "The Peak element in the array is  at index :" << findPeakElement(v) << " "
         << "the value is " << v[findPeakElement(v)] << endl;
    cout << "This is the program for finding PEAK ELEMENT IN SORTED ARRAY \n";
    return 0;
}
/*
interviewbit : https://www.interviewbit.com/problems/find-a-peak-element/ (rem)

*/