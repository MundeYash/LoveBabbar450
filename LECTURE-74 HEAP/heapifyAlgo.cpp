// heapify Algorithm : It is algorithm that  arrange the nodes at its correct position after insertion or deletion in min-heap accordingly
// this is min heap implementation
#include <bits/stdc++.h>
using namespace std;

class minheap
{

public:
    int arr[1000];
    int size; // the number of elements in the heap after excluding the 0th index

    // default constructor
    minheap()
    {
        size = 0;
        arr[0] = -1; // setting the garbage value and blocking of the 0 th index
    }

    // function for inserting the element / node in the min heap

    void insert2heap(int val)// time : O(log n )
    {
        // step 1 ; increment the size and add the element at the last index

        size = size + 1;
        arr[size] = val;

        // step 2 : placing of all the nodes at its correct position

        int index = size;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] > arr[index])
            {

                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // function for deleting the element / node in the heap
    // (deletion an element in heap ) : means deletion of the root node element in the heap
    void deletion2Heap()
    {
        // base caase 
        if (size == 0 ){
            cout<<"Nothing to delete "<<endl;
            return ;
        }

        // step 1: put the last index value to the root(starting index )
        arr[1 ] = arr[size];

        // step2 : reduce the size by the one(delete the node )
        size = size - 1;

        int i = 1;

    // step3 : propage the all nodes to its correct position 
        while (i < size)
        {
            int leftChild = 2 * i;
            int rightchild = 2 * i + 1;

            if (leftChild <= size and arr[leftChild] < arr[i] and arr[leftChild] < arr[rightchild])
            {
                swap(arr[i], arr[leftChild]);
                i = leftChild;
            }

            else if (rightchild <= size and arr[rightchild] < arr[i] and arr[rightchild] < arr[leftChild])
            {

                swap(arr[rightchild], arr[i]);
                i = rightchild;
            }
            else
            {
                // all values are arrange to their correct position
                return;
            }
        }
    }

    // function for printing the node
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// function for heapify algo for min heap 

void heapify(int arr[] , int n , int i ){
    int smallest =i ; 
    int leftChild = 2*i ; 
    int rightChild = 2* i + 1; 

    if (leftChild<=n and arr[leftChild]<arr[smallest]){
        smallest = leftChild ; 

    }
    if (rightChild<=n and arr[rightChild]<arr[smallest]){
        smallest = rightChild ; 

    }

    if (smallest !=i ){
        // smallest index value is changed 
        swap(arr[smallest] , arr[i]) ; 
        heapify(arr , n , smallest);
    }

}
int main()
{
    minheap h;
    h.insert2heap(3);
    h.insert2heap(13);
    h.insert2heap(31);
    h.insert2heap(93);
    h.insert2heap(373);

    h.print();

    // deletion
    h.deletion2Heap();
    cout << "After deletion : ";

    h.print();

// Heapify (heap order property ) for Min heap 

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(int); 
    n-- ; // for the garbage index value 


    // n to n /2 index range are already heapified for the min- heap (leaf nodes )

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
code studio : https://www.codingninjas.com/studio/problems/min-heap_4691801?leftPanelTab=0  (rem 

https://www.codingninjas.com/studio/problems/min-heap-implementation_5480527?leftPanelTab=0)

*/