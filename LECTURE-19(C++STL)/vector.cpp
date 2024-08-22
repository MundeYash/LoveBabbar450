#include <bits/stdc++.h>
#include <vector> // header file for the vector
using namespace std;
// VECTOR is dynamic memory : Vector is a kind of data structure which double its size when filled completely
int main()
{
    // declaration and intialisation of vector

    vector<int> v = {1, 2, 3, 4};
    // printing the vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    // Insertion : -> (push_back)operation to add element at the last of the vector
    v.push_back(3);
    cout << "The element present in the back /last of vector is : " << v.back() << endl; // to print the last element
    cout << "The element present in front of vector is : " << v.front() << endl;         // to print the first element in the vector

    // Deletion :->(pop_back) Operation is used  to remove the element from last
    v.pop_back();
    // printing the elements using the auto iterator
    for (auto ch : v)
    {
        cout << ch << " ";
    }
    cout << endl;
    // intializing the whole vector with a single value
    vector<bool> name(4, 1);
    for (auto ch : name)
    {
        cout << ch << " ";
    }

    // Capacity : Maximum elements the vector able to store :->(capcity())  operation is used
    cout << "\nThe capacity of given vector is : " << v.capacity() << endl;

    // Size of vector :->(size()): already filled or added elements in the vector is size and (size()) Operation is used to access the size of the vector
    cout << "The size of the vector is :" << v.size() << endl;
    // Compelete Deletion of all elements ->(clear()) Operation is used  to clear all the elements of the vector
    v.clear();
    // Inbuilt function inside the vector stl
    cout << "To get size :" << v.size() << endl;
    cout << "To get Capacity  :" << v.capacity() << endl;

    // Check vector is empty or not : (.empty())Operation is used
    cout << "Our given vector is empty or not " << v.empty() << endl;

    return 0;
}

/*

Reference websites : https://en.cppreference.com/w/cpp/header/vector

*/