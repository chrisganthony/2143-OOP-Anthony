///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Chris Anthony
// Email:            chrisanthony97@hotmail.com
// Label:            A02
// Title:            Linked List Class
// Course:           CMPS 2143
// Semester:         Spring 2020
//
// Description:
//       This program implements a class that allows a linked list to be used just like 
//       an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
//       array elements, but really it traverses the list to find the specified node using
//       an index value. It also overloads the "+" and "-" signs allowing a user to "add"
//       or "push" items onto the end of the list, as well as "pop" items off the end of our 
//       array.   
//
// Usage: 
//      - $ ./main filename
//      - This will read in a file containing whatever values to be read into our list/array. 
//      
// Files:            
//      main.cpp    : driver program 
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100];         //creates an array of size 100 

struct Node         // node setup for a list.
{
    int x;          // simple integer data.
    Node *next;     // pointer to the next node
    Node()          // default constructor
    {
        x = -1;
        next = NULL;
    }
    Node(int n)     // overloaded constructor
    {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      This class implements several methods to perform different operations on a linked list.
 * 
 * Public Methods:
 *                          List()                             
 *      void                Push(int val)
 *      void                Insert(int val)
 *      void                PrintTail()
 *      int                 Pop()
 *      int                 operator[](int index)
 * 
 * Usage: 
 * 
 *      List L1;            // Create Instance of List
 *      L1.Push(i);         // adds an integer value to the list
 *      L1.PrintTail();     // prints the last element in the list
 */

class List
{
  private:
    Node *Head;
    Node *Tail;
    int Size;

  public:
   
/**
 * Public: Default Constructor
 */
   
    List()                  
    {
        Head = Tail = NULL;
        Size = 0;
    }
/**
 * Push
 * Description:
 *     Adds an integer value to the list 
 * Params:
 *     int val  : integer value to be added
 * Returns:
 *     void
 */
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

/**
 * Public: Insert
 * Description:
 *       Inserts an integer value to the list
 * Params:
 *       int val     : integer value to be added 
 * Returns:
 *     void
 */

    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }

/**
 * Public: PrintTail
 *
 * Description:
 *      Prints the tail's value of the list
 * 
 * Params:
 *
 *     Void
 *
 * Returns:
 *
 *     void
 */
    void PrintTail()
    {
        cout << Tail->x << endl;
    }

/**
 * Public: Print
 *
 * Description:
 *      Prints the contents of the list
 * 
 * Params:
 *
 *     Void
 *
 * Returns:
 *
 *     List      :  a linked list 
 */
    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }
 /**
 * Pop
 * Description:
 *     Removes an item from the list
 * Params:
 *     void
 * Returns:
 *    int      : integer value
 */
    // not implemented 
    int Pop()
    {
        Size--;
        return 0; 
    }

    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1;      // first instance of List
    List L2;      // second instance of List


    // for loop to add values to the list
    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();     
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}
