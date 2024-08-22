#include <bits/stdc++.h>
using namespace std;
// Creation of Node structure of lik list
class Node
{
public:
    int data;
    Node *next;

    // default constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // destructor calling
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for the Node with data : " << this->data << endl;
    }
};

// function for inserting node in the circular link list

void insertNode(Node *&tail, int element, int d)
{
    // case 1: Zero number of nodes
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        // means nodes are present in the link list (Non- Empty List )
        // Step 1: find the location
        Node *curr = tail;

        // search the element in the link list
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // Element node is found and curr is pointing to that node

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
    return;
}

// function for deleting node
void deleteNode(Node *&tail, int element)
{
    // No element in the link list
    if (tail == NULL)
        return;

    // two pointers used pre , curr
    Node *prev = tail;
    Node *curr = prev->next;

    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    // if only one node is there 
    if (curr == prev ){
        tail = NULL;
        
    }

    // if more than 1 nodes are present 
    else if (tail == curr)
    {
        tail = prev;
    }

    
    curr->next = NULL;
    delete curr;
    return;
}

// Function for traversing the link list (prinitng / length )

void print(Node *tail)
{
    Node *temp = tail;
    // case of empty list when list is empty (because here tail ka data is null which is not accessible )
    if (tail == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << "->";
        tail = tail->next;

    } while (tail != temp);
    cout << "<-" << endl;
}


int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    // insertNode(tail, 3, 5);
    // print(tail);

    // insertNode(tail, 5, 7);
    // print(tail);

    // insertNode(tail, 7, 9);
    // print(tail);

    // insertNode(tail, 5, 6);
    // print(tail);

    // insertNode(tail, 9, 10);
    // print(tail);

    // insertNode(tail, 3, 4);
    // print(tail);

    deleteNode(tail, 3);
    print(tail);
}