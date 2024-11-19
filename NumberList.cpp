#include <iostream>
#include "NumberList.h"
using namespace std;

// appendNode: Appends a node containing num to the end of the list
void NumberList::appendNode(double num)
{
    ListNode* newNode;  // To point to a new node
    ListNode* nodePtr;  // To move through the list

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // If there are no nodes in the list, make newNode the first node.
    if (!head)
        head = newNode;
    else
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

// displayList: Displays the values stored in each node
void NumberList::displayList() const
{
    ListNode* nodePtr = head; // To move through the list

    // While nodePtr points to a node, traverse the list.
    while (nodePtr)
    {
        // Display the value in this node.
        cout << "\t" << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}

// insertNode: Inserts a node with num in sorted order
void NumberList::insertNode(double num)
{
    ListNode* newNode;                  // A new node
    ListNode* nodePtr;                  // To traverse the list
    ListNode* previousNode = nullptr;  // The previous node

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;

    if (!head) // If the list is empty, make newNode the first node
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == nullptr) // Insert as the first node
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

// deleteNode: Deletes the node containing num
void NumberList::deleteNode(double num)
{
    ListNode* nodePtr = head;       // To traverse the list
    ListNode* previousNode = nullptr; // To track the previous node

    if (!head) // If the list is empty, do nothing
        return;

    if (head->value == num) // If the first node is to be deleted
    {
        head = head->next;
        delete nodePtr;
    }
    else
    {
        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr) // If the node was found, remove it
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

// mergeArray: Merges an array into the list in sorted order
void NumberList::mergeArray(const double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insertNode(arr[i]);
    }
}

// Destructor: Deletes every node in the list
NumberList::~NumberList()
{
    ListNode* nodePtr = head; // To traverse the list
    ListNode* nextNode;       // To point to the next node

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}
