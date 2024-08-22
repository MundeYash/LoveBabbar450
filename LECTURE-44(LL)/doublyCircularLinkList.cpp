#include <bits/stdc++.h >
using namespace std;

// Circular Doubly Link -List
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // default constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        if (this->prev != NULL)
        {
            delete prev;
            this->prev = NULL;
        }

        cout << "Memory free for node with data : " << value << endl;
    }
};

// function for inserting node in circular doubly link list
void insertNode(Node *&tail, int element, int d)
{

    // if no node is present
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        temp->prev = temp;
        temp->next = temp;
        tail = temp;
    }
    else
    {
        // Nodes are present

        // find the location of the element
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // here our curr pointer points to the element node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next->prev = temp;
        temp->prev = curr;
        curr->next = temp;
    }
    return;
}
// function for deleting the circular doubly link list
void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        // means no node is present / empty list
        return;
    }
    else
    {

        // two Pointers prev and curr is usesd
        Node *previous = tail;
        Node *curr = tail->next;

        while (curr->data != element)
        {
            previous = curr;
            curr = curr->next;
        }

        previous->next = curr->next;
        // if only one node is there
        if (curr == previous)
        {
            tail = NULL;
        }

        // if more than 1 nodes are present
        else if (tail == curr)
        {
            tail = previous;
        }

        curr->next->prev = previous;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
        return;
    }
}

// function for printing the circular doubly link list
void printLL(Node *tail)
{
    // case of empty list when list is empty (because here tail ka data is null which is not accessible )
    if (tail == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;

    } while (temp != tail);
    cout << "<-" << endl;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    printLL(tail);

    insertNode(tail, 3, 5);
    printLL(tail);

    insertNode(tail, 5, 7);
    printLL(tail);
    insertNode(tail, 7, 9);
    printLL(tail);

    insertNode(tail, 5, 6);
    printLL(tail);

    deleteNode(tail, 3);
    printLL(tail);
    return 0;
}
