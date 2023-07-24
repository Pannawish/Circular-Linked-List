#include "node.h"

class CircularLL
{
private:
     NodePtr head = NULL, tail = NULL;

public:
    void insert(int n);
    bool remove(int n);
    void print(int = 1);
};

void CircularLL::insert(int n)
{
    NodePtr new_node = new NODE(n);

    if (head == NULL)
    {
        head = tail = new_node;
        tail->nextPtr = head;
        return;
    }
    if (n < head->value)
    {
        new_node->nextPtr = head;
        tail->nextPtr = new_node;
        head = new_node;
        return;
    }
    NodePtr temp = head;
    while (temp->nextPtr != head && temp->nextPtr->value < n)
        temp = temp->nextPtr;
    new_node->nextPtr = temp->nextPtr;
    temp->nextPtr = new_node;
    if (temp == tail)
        tail = new_node;
}

bool CircularLL::remove(int n)
{

    // Empty list
    if (head == NULL)
        return false;

    // Out of range
    if (n < head->value || n > tail->value)
        return false;

    // Delete head
    if (head->value == n)
    {
        tail->nextPtr = head->nextPtr;
        NodePtr temp = head;
        head = tail->nextPtr;
        delete temp;
        return true;
    }

    // Any other value in between
    NodePtr temp = head;
    for (int first = 1; temp->nextPtr->value != n && (temp != head || first--); temp = temp->nextPtr)
        ;

    // Not found
    if (temp->nextPtr->value != n)
        return false;

    // Found that number
    NodePtr toRemove = temp->nextPtr;
    temp->nextPtr = toRemove->nextPtr;

    // If that number is tail
    if (toRemove == tail)
        tail = temp;
    delete toRemove;
    return true;
}

void CircularLL::print(int round)
{
    for (NodePtr temp = head; temp != head || round--; temp = temp->nextPtr)
        cout << temp->value << " -> ";
    cout << "(head)" << endl;
}