#include <bits/stdc++.h>
using namespace std;

// implementation of the heap data structure
/*
What is heap : it is a data structure that is complete binary tree , follows the heap order property  , evey level except the last level is fully filled and insertion of nodes/ data is done from left to right order
max heap : parent have higher value than its childs 
min heap ;parent node have always smaller node than its children nodes 

properties and formulaes

// for 0 based index and no garbage value left 
node -> ith index
parent = (i-1/2) ;
left child = 2*i +1 ;
right child = 2*i + 2 ;

// for 1 based index and garbage value at the 0th index 
node -> ith index
parent = (i/2) ;
left child = 2*i ;
right child = 2*i + 1 ;



// operations in heap

1. insertion: push 
2. deletion: pop
3. heapify property
4. Top element 
*/

class heap
{
public:
    int arr[1000];
    int size;

    // default constructor
    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    // function for inserting a node in the heap
    void insertion2heap(int val)
    {
        // time  complexity  : O(log n )

    // step1 : insert at the end 
        size = size + 1; // due to addtino of node
        arr[size] = val;

        // heapify procedure
        int index = size; // the index of added node value

        while (index > 1)
        {
        //  Step 2 : parent find and check if its follows the property of heap or not  , other wise make it correct position
            int parent = index / 2; // index of the parent

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return; // means now heapify order is satified
            }
        }
    }

    // function for deleting a element in the heap

    void deletionFromheap()
    {
        // time complexity : O(log n )

        // deletion means  :deletion of the root node in the heap

        // condition check
        if (size == 0)
        {
            // nothing to delete

            cout << "Nothing to delete " << endl;
            return;
        }

        // step1  : put the last node at the starting index
        arr[1] = arr[size];

        // step2  :Remove/ delete  the last node at size index
        size--; // reduce the size by one

        // step 3 : heapify order satisfy : Taking root node to its correct position
        int i = 1;
        int largest = i; // the largest value of node among the parent , left child and the right child

        while (i < size)
        {

            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            if (leftChild <= size and arr[i] < arr[leftChild] and arr[leftChild] > arr[rightChild])
            {

                swap(arr[leftChild], arr[i]);
                i = leftChild;
            }

            else if (rightChild <= size and arr[i] < arr[rightChild] and arr[rightChild] > arr[leftChild])
            {
                swap(arr[rightChild], arr[i]);
                i = rightChild;
            }

            else
            {
                // everytihing at its correct position

                return;
            }
        }
    }

    // function for printing the heap

    void print()
    {
        for (int i = 1; i <= size; i++)
        { // because no element is present in the oth index till the last index
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// function for heapify alogrithm
void heapify(int arr[], int n, int i)
{

    // time complexity : O(Log n) 
// assumption is 1 based indexing 
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if (leftChild <= n and arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild <= n and arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);

        // work for the other possible options

        heapify(arr, n, largest);
    }
}
int main()
{

    // heap object creation
    heap h;

    // insertion
    h.insertion2heap(41);
    h.insertion2heap(14);
    h.insertion2heap(4);
    h.insertion2heap(43);
    h.insertion2heap(24);
    h.insertion2heap(54);

    // h.insertion2heap(50);
    // h.insertion2heap(55);
    // h.insertion2heap(53);
    // h.insertion2heap(52);
    // h.insertion2heap(54);

    h.print();

    // deletion
    h.deletionFromheap();

    h.print();

    // heapify function implementation

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(int);

    // to not include 0th index
    n = n - 1;

    // n to n /2 index range are already heapified for the max- heap (leaf nodes )

    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }

    // for checking whether the changes are reflected or not

    cout << "Heapify : " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/*

article : 
practice : https://www.codingninjas.com/studio/guided-paths/data-structures-algorithms/content/118823/offering/1382117 (rem )

*/