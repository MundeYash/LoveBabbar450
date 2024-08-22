#include <bits/stdc++.h>
using namespace std;
// Doubly Link list
class Node
{
public:
    int data;   // data inside the node
    Node *prev; // PREVIOUS Pointer
    Node *next; // Next pointer

    // defautl constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor
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
// function for printing the link list
void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// function for getting the length of the link list
int lengthLL(Node *&head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// function for inserting the node at the front
void insertAtHead(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        return;
    }
    else
    {
        // creation of new node
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }
}

// function for inserting the node at the end / last
void insertAtTail(Node *&tail, int d)
{
    if (tail == NULL)
    {
        // means last node
        Node *temp = new Node(d);
        tail = temp;
        return;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        return;
    }
}

// function for inserting the node at particular kth position
void insertAtMiddle(Node *&head, Node *&tail, int k, int d)
{
    // if k is starting node
    if (k == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < k - 1)
    {
        temp = temp->next;
        count++;
    }

    // if k is last node
    if (temp->next == NULL)
    {
        // means insertion to done at last node
        insertAtTail(tail, d);
        return;
    }

    // case 3 : means k is somewhere in the middle

    // creation of new node with d data(main steps )
    Node *nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    temp->next->prev = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->prev = temp;
}

// Deletion
// Function for deletion at the front

void deletionAtFront(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
}

// function for deletion at the end

// function for deletion node at k position
void deleteAtMiddle(Node *&head, Node *&tail, int k)
{
    // if Only one node
    if (k == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        // means k is between 2 to n

        // step 1 : move to the location of current pointer
        Node *prev = NULL;
        Node *curr = head;
        int count = 1;
        while (count < k)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        // checking for last node
        if (curr->next == NULL)
        {
            tail = prev;
        }

        // here our current pointer moves to kth position
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL; // just to free the memory
        delete curr;       // memory freed
    }
}
int main()
{
    Node *node1 = new Node(3);

    Node *head = node1;
    cout << head->data << endl;
    cout << head->next << endl;
    cout << head->prev << endl;

    // setting of tail pointer of the link list
    Node *tail = head;

    cout << endl
         << endl;
    insertAtHead(head, 41);

    printLL(head);
    insertAtHead(head, 31);

    insertAtTail(tail, 45);
    printLL(head);

    // insertion at middle k position
    insertAtMiddle(head, tail, 3, 115);
    printLL(head);
    insertAtMiddle(head, tail, 1, 100);
    printLL(head);

    deleteAtMiddle(head, tail, 6);
    printLL(head);

    cout << "The length of the link list is : " << lengthLL(head) << endl;
    cout << "Head :" << head->data << endl;
    cout << "Tail :" << tail->data << endl;
}

/*
Practice Links :

*/