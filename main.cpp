#include <iostream> //for standard input-output operations
#include "input.h" //for custom input functions
#include "MyList.h" //for linked list template operations
#include "NumberList.h" //for number list operations

using namespace std; //avoid prefixing std:: everywhere

//prototype for displaying menu options
int menuOption();

//function prototypes for challenges
void Challenge1();
void Challenge2();
void Challenge3();
void Challenge7();
void Challenge8();
void Challenge12();

int main()
{
    do
    {
        switch (menuOption()) //handle menu selection
        {
        case 0: exit(1); break; //exit program
        case 1: Challenge1(); break; //run challenge 1
        case 2: Challenge2(); break; //run challenge 2
        case 3: Challenge3(); break; //run challenge 3
        case 7: Challenge7(); break; //run challenge 7
        case 8: Challenge8(); break; //run challenge 8
        case 12: Challenge12(); break; //run challenge 12
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause"); //pause before showing menu again

    } while (true);

    return EXIT_SUCCESS; //program executed successfully
}

int menuOption()
{
    system("cls"); //clear the screen before displaying menu

    cout << "\n\tChapter 18 -- Linked Lists by Francisco Bumanglag";
    cout << "\n\t" << string(60, char(205));
    cout << "\n\t1. Challenge 1: Your Own Linked List";
    cout << "\n\t2. Challenge 2: List Print";
    cout << "\n\t3. Challenge 3: List Copy Constructor";
    cout << "\n\t7. Challenge 7: Member Removal by Position";
    cout << "\n\t8. Challenge 8: List Template";
    cout << "\n\t12. Challenge 12: Double Merge";
    cout << "\n\t" << string(60, char(196));

    //decorative line below menu options
    cout << "\n\t" << string(90, char(196));

    //display option for exiting the program
    cout << "\n\t0. Exit the Program";

    //bottom decorative line for menu
    cout << "\n\t" << string(90, char(205));

    return inputInteger("\n\tOption: ", 0, 12); //return user input
}

void Challenge1()
{
    MyList<int> test; //initialize integer linked list

    test.appendNode(666); //add node with value 666
    test.insertNode(555); //insert node with value 555
    test.displayList(); //display the list
    test.deleteNode(666); //remove node with value 666
}

void Challenge2()
{
    MyList<int> test; //initialize integer linked list

    test.appendNode(666); //add node with value 666
    test.insertNode(555); //insert node with value 555
    test.deleteNode(666); //remove node with value 666

    srand(static_cast<unsigned int>(time(0))); //seed random generator

    for (int i = 1; i <= 10; i++)
        test.appendNode(rand() % 1000 + 1); //add random numbers to list

    test.print(); //print all nodes in the list
}

void Challenge3()
{
    MyList<int> original; //initialize original list

    original.appendNode(10); //add value 10 to list
    original.appendNode(20); //add value 20 to list
    original.appendNode(30); //add value 30 to list

    cout << "\n\tOriginal list: ";
    original.displayList(); //display the original list

    MyList<int> copy(original); //use copy constructor

    cout << "\n\tCopied list: ";
    copy.displayList(); //display the copied list
}

void Challenge7()
{
    MyList<int> test; //initialize integer linked list

    for (int i = 1; i <= 5; i++)
        test.appendNode(i * 10); //populate list with multiples of 10

    cout << "\n\tInitial list: ";
    test.displayList(); //display the initial list

    cout << "\n\tDeleting node at position 0 (head):" << endl;
    test.deleteNodeAt(0); //remove the head node
    test.displayList(); //display updated list

    cout << "\n\tDeleting node at position 2:" << endl;
    test.deleteNodeAt(2); //remove node at position 2
    test.displayList(); //display updated list

    cout << "\n\tAttempting to delete at out-of-range position (10):" << endl;
    test.deleteNodeAt(10); //attempt to remove invalid position
    test.displayList(); //display list after invalid deletion
}

void Challenge8()
{
    MyList<int> intList; //integer linked list
    intList.appendNode(10); //add value 10
    intList.appendNode(20); //add value 20
    intList.appendNode(30); //add value 30
    cout << "\n\tInteger list: ";
    intList.displayList(); //display integer list

    MyList<double> doubleList; //double linked list
    doubleList.appendNode(1.1); //add value 1.1
    doubleList.appendNode(2.2); //add value 2.2
    doubleList.appendNode(3.3); //add value 3.3
    cout << "\n\tDouble list: ";
    doubleList.displayList(); //display double list

    MyList<string> stringList; //string linked list
    stringList.appendNode("Alice"); //add string Alice
    stringList.appendNode("Bob"); //add string Bob
    stringList.appendNode("Charlie"); //add string Charlie
    cout << "\n\tString list: ";
    stringList.displayList(); //display string list

    MyList<char> charList; //character linked list
    charList.appendNode('A'); //add character A
    charList.appendNode('B'); //add character B
    charList.appendNode('C'); //add character C
    cout << "\n\tCharacter list: ";
    charList.displayList(); //display character list
}

void Challenge12()
{
    NumberList list; //initialize number list

    double values[] = { 3.1, 5.6, 1.4, 4.8, 2.2 }; //array of double values
    int size = sizeof(values) / sizeof(values[0]); //calculate array size

    cout << "\n\tMerging array into the list...\n";
    list.mergeArray(values, size); //merge array into list

    cout << "\n\tList after merging:\n";
    list.displayList(); //display merged list
}
