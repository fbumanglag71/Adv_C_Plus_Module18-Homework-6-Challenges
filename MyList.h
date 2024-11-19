// A class template for holding a linked list.
// The node type is also a class template.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

//*********************************************
// The ListNode class creates a type used to  *
// store a node of the linked list.           *
//*********************************************

template <class T>
class ListNode
{
public:
    T value;           // Node value
    ListNode<T>* next; // Pointer to the next node

    // Constructor
    ListNode(T nodeValue)
    {
        value = nodeValue;
        next = nullptr;
    }
};

//*********************************************
// MyList class                               *
//*********************************************

template <class T>
class MyList
{
private:
    ListNode<T>* head; // List head pointer

    // Helper function to copy nodes from another list
    void copyList(const MyList<T>&);

public:
    // Constructor
    MyList() { head = nullptr; }

    // Copy constructor
    MyList(const MyList<T>& other) { head = nullptr; copyList(other); }

    // Destructor
    ~MyList();

    // Linked list operations
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void deleteNodeAt(int); // For Challenge 7
    void mergeArray(const T[], int); // For Challenge 12
    void displayList() const;
    void print() const;
};

//**************************************************
// Helper function to copy nodes from another list *
//**************************************************

template <class T>
void MyList<T>::copyList(const MyList<T>& other)
{
    ListNode<T>* otherNode = other.head; // Start from the head of the other list

    // Traverse the other list
    while (otherNode)
    {
        // Append each node's value to this list
        appendNode(otherNode->value);
        otherNode = otherNode->next;
    }
}

//**************************************************
// appendNode appends a node containing the value  *
// passed into newValue, to the end of the list.   *
//**************************************************

template <class T>
void MyList<T>::appendNode(T newValue)
{
    ListNode<T>* newNode = nullptr;  // To point to a new node
    ListNode<T>* nodePtr = nullptr; // To move through the list

    // Allocate a new node and store newValue there.
    newNode = new ListNode<T>(newValue);

    // If there are no nodes in the list
    // make newNode the first node.
    if (!head)
        head = newNode;
    else // Otherwise, insert newNode at end.
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Find the last node in the list.
        while (nodePtr->next)
            nodePtr = nodePtr->next;

        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head.          *
//**************************************************

template <class T>
void MyList<T>::displayList() const
{
    ListNode<T>* nodePtr = nullptr; // To move through the list

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse
    // the list.

    cout << "\n";
    while (nodePtr)
    {
        // Display the value in this node.
        cout << "\t" << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template <class T>
void MyList<T>::insertNode(T newValue)
{
    ListNode<T>* newNode = nullptr;       // A new node
    ListNode<T>* nodePtr = nullptr;       // To traverse the list
    ListNode<T>* previousNode = nullptr; // The previous node

    // Allocate a new node and store newValue there.
    newNode = new ListNode<T>(newValue);

    // If there are no nodes in the list
    // make newNode the first node
    if (!head || head->value >= newValue)
    {
        newNode->next = head;
        head = newNode;
    }
    else // Otherwise, insert newNode in order
    {
        nodePtr = head;

        while (nodePtr->next && nodePtr->next->value < newValue)
        {
            nodePtr = nodePtr->next;
        }

        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
    }
}

//**************************************************
// The deleteNode function searches for a node     *
// with searchValue as its value and removes it.   *
//**************************************************

template <class T>
void MyList<T>::deleteNode(T searchValue)
{
    ListNode<T>* nodePtr = head;
    ListNode<T>* previousNode = nullptr;

    if (!head) // If the list is empty, do nothing
        return;

    if (head->value == searchValue) // If the first node is to be deleted
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        while (nodePtr && nodePtr->value != searchValue) // Search for the node
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr) // If the node was found
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

//**************************************************
// deleteNodeAt deletes the node at a given        *
// position. A position of 0 deletes the head.     *
//**************************************************

template <class T>
void MyList<T>::deleteNodeAt(int position)
{
    if (!head) // If the list is empty, do nothing
        return;

    if (position == 0) // Delete the first node
    {
        ListNode<T>* temp = head; // Temporary pointer to the head
        head = head->next;       // Move the head to the next node
        delete temp;             // Delete the original head
        return;
    }

    ListNode<T>* nodePtr = head;       // To traverse the list
    ListNode<T>* previousNode = nullptr; // To keep track of the previous node
    int currentIndex = 0;

    // Traverse the list to find the node at the specified position
    while (nodePtr && currentIndex < position)
    {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
        currentIndex++;
    }

    // If position is out of range or if previousNode is NULL, do nothing
    if (!nodePtr || !previousNode)
        return;

    // Remove the node at the specified position
    previousNode->next = nodePtr->next;
    delete nodePtr;
}

//**************************************************
// mergeArray merges values from an array into the *
// linked list in order.                           *
//**************************************************

template <class T>
void MyList<T>::mergeArray(const T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insertNode(arr[i]);
    }
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template <class T>
MyList<T>::~MyList()
{
    ListNode<T>* nodePtr = nullptr;  // To traverse the list
    ListNode<T>* nextNode = nullptr; // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

//**************************************************
// print shows the value stored in each node       *
// of the linked list pointed to by head.          *
//**************************************************

template <class T>
void MyList<T>::print() const
{
    ListNode<T>* nodePtr = head; // Start from the head
    while (nodePtr) // Traverse the list
    {
        cout << "\n\t" << nodePtr->value << " "; // Display the value
        nodePtr = nodePtr->next; // Move to the next node
    }
    cout << endl;
}

#endif
