#include <bits/stdc++.h>
using namespace std;
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
};
// function for inserting node in the link list
void insertAtEnd(Node *&head, int d)
{
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
    return;
}
// function for printing the link list
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
// Function for Reverse a link
void reverseLL(Node *&head)
{
    // time : O(n)
    // Approach 1; Iterative Approach

    // if only one node/ no node in link list
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *forward = NULL;
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return;
}

// Approach -2 Recursive Approach

// We need a helper function solve for the recursive solution
void solve(Node *&head, Node *curr, Node *prev)
{
    // base case
    if (curr == NULL)
    { // whole link list is traveresed
        head = prev;
        return;
    }
    // Recursive case
    Node *forward = curr->next;
    solve(head, forward, curr); // this part of linklist is reversed by the recursion
    curr->next = prev;
}
void reverseLL2(Node *&head)
{// time : O(N) , space :O(n)
    Node *curr = head;
    Node *prev = NULL;
    solve(head, curr, prev);
    return;
}

// Approach 3  : -> using Recursion + Optimisation
Node*  reverseLL3(Node *head)
{// time : O(N) , space :O(n)

// base case 
 if (head == NULL || head ->next == NULL){
    // no nodes , only one nodes are present 
    return head ;
 }

 // recursive case 
 Node* chotaHead = reverseLL3(head->next);
 head ->next ->next = head ; // breaking connection 
 head ->next = NULL;
 return chotaHead ;

}

int main()
{
    Node *head = new Node(4);
    insertAtEnd(head, 3);
    insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    printLL(head);
    // reverseLL(head);
    // reverseLL2(head);
    head = reverseLL3(head);

    printLL(head);
    return 0;
}
/*
https://leetcode.com/problems/reverse-linked-list/

*/