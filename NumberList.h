#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
    // Declare a structure for the list
    struct ListNode
    {
        double value;           // The value in this node
        struct ListNode* next;  // To point to the next node
    };

    ListNode* head; // List head pointer

public:
    // Constructor
    NumberList() { head = nullptr; }

    // Destructor
    ~NumberList();

    // Linked list operations
    void appendNode(double);                // Appends a node to the end of the list
    void insertNode(double);                // Inserts a node in sorted order
    void deleteNode(double);                // Deletes a node by value
    void displayList() const;               // Displays all values in the list
    void mergeArray(const double[], int);   // Merges an array into the list in sorted order
};

#endif
