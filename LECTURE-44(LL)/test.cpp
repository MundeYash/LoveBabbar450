#include <iostream>
using namespace std;
void takeInput(int &data)
{
    cin >> data;
}
// LInk List
class node
{
public:
    int data;
    node *next;
    // this is default CONSTRUCTOR
    node(int d)
    {
        // cout<<"Inside the Default Constructor \n" ;
        this->data = d;
        this->next = NULL;
    }

    // destructor for deleting the nodes
    ~node()
    {
        // just to get the idea which node is deleted
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory free for node with data : " << value << endl;
    }
};
// Function for priting of a link list node

void print(node *head)
{
    // creating temp pointer  so that our head does not chage
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// *********Insertion

// Insert at head (or Insert at front )(done)

void InsertAtfront(node *&head, int d) // by reference head is passed to update the head in orginal ll
{
    // step 1 creation of a node named temp dynamically
    node *temp = new node(d);

    // step 2 temp -> next = head ;
    temp->next = head;

    // step 3 head = temp ;
    head = temp;
}
// Insert at the end (or Insert at the tail )

void InsetAtEnd(node *&tail, int d)
{

    // step 1 creation of node temp dynamically storing data
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
// function for inserting a node in the middle of the link list
void insertAtkMiddle(node *&head, node *&tail, int k, int d)
{
    // inserting the node at kth position with data d
    // Step1  : go to k-1 location

    // conditions
    // case 1 : if k==1  , means inserting at the starting node
    if (k == 1)
    {
        InsertAtfront(head, d);
        return;
    }

    // case 2 : k is between 1 and n

    node *temp = head;
    int count = 1;
    while (count < k - 1)
    {
        temp = temp->next;
        count++;
    }
    // case 3 : k== n  , means inserting at the last node
    //  update the tail
    if (temp->next == NULL)
    {
        // means last node
        InsetAtEnd(tail, d);
        return;
    }

    node *nodeToinsert = new node(d);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;

    return;
}

//*****DELETION OPERATION IN LINK LIST

// function for deleting node
void deleteNode(int position, node *&head, node *&tail)
{

    // if position is starting node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;

        // memory free
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // means position lies somewhere from the 2 to last node

        // step 1 : move to the location of current pointer
        node *prev = NULL;
        node *curr = head;
        int count = 1;
        while (count < position)
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
        prev->next = curr->next;
        curr->next = NULL; // just to free the memory
        delete curr;       // memory freed
    }
}
int main()
{
    //  node head  ; // statically creation
    int d = 5;
    // cin>> d ;
    node *node1 = new node(d); // dynamically creation
    // for printing data and address of link list using node1
    cout << "Data is :" << node1->data << endl;
    cout << "Next of node is :" << node1->next << endl;
    node *head = node1;
    print(node1);

    //   // Insertion
    //   int data ;

    InsertAtfront(head, 78);
    InsertAtfront(head, 64);
    node *tail = node1;
    InsetAtEnd(tail, 50);
    InsetAtEnd(tail, 10);
    InsetAtEnd(tail, 30);
    print(head);

    // insert at the k th position of the link list
    insertAtkMiddle(head, tail, 3, 45);
    print(head);

    insertAtkMiddle(head, tail, 1, 24);

    insertAtkMiddle(head, tail, 9, 11);
    print(head);

    // deletion operations

    // delete at front
    deleteNode(1, head, tail);

    // deletion at the end
    deleteNode(8, head, tail);

    // deletion at the mid
    deleteNode(3, head, tail);
    print(head);
   

    // checking the pointer of head and tail
    cout << "head :" << head->data << endl;
    cout << "Tail :" << tail->data << endl;
    cout << "This is Lecture ->44 Link List \n";
    return 0;
}