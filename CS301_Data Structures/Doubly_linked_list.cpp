#include <iostream>      // include header for input/output
using namespace std;     // allows use of cout, cin, etc. without std::


//  Node Class - represents a single element in the list

class Node 
{
public:
    int data;            // stores the data value of the node
    Node *next_addr;     // pointer to the next node in the list
    Node *pre_addr;     // pointer to the previous node in the list
};


//  Linked_list Class - manages all nodes

class Linked_list 
{
public:
    Node *head = NULL;   // pointer to the first node in the list (NULL means empty list)
    Node *tail = NULL;   // pointer to the last node in the list (NULL means empty list)

    
    // Function: setdata()
    // Purpose: Insert a new node at the end
    
    void setdata() 
    {
        int n;
        cout << "\nPlease Enter Value: ";
        cin >> n;                            // take value from user

        Node *new_node = new Node;           // dynamically create a new node using 'new'
        new_node->data = n;                  // store user's value in node
        new_node->next_addr = NULL;          // since it’s the last node for now

        if (head == NULL)                    // if the list is empty
        {                 
            head = new_node;                 // make this node the first node (head)
        } 
        else                                 // otherwise, find the last node
        {                           
            Node *ptr = head;                // start from the first node
            while (ptr->next_addr != NULL) { // move till last node (where next_addr is NULL)
                ptr = ptr->next_addr;
            }
            ptr->next_addr = new_node;       // connect last node to new node
        }
        cout << "\nNew node inserted successfully....";
    }

    
    // Function: count()
    // Purpose: Count total number of nodes
    
    void count() 
    {
        if (head == NULL)                    // if list is empty
        {                 
            cout << "\nLinked List is Empty....";
        } 
        else 
        {
            int n = 0;                       // counter for nodes
            Node *ptr = head;                // start from first node
            while (ptr != NULL) {            // continue till last node
                n++;                         // increase count
                ptr = ptr->next_addr;        // move to next node
            }
            cout << "\nTotal Nodes are: " << n;
        }
    }

    
    // Function: search()
    // Purpose: Search for a specific value
    
    void search() 
    {
        if (head == NULL)                     // check if list empty
        {                 
            cout << "\nLinked List is Empty....";
        } else 
        {
            int n, found = 0, position = 1;
            cout << "\nPlease Enter the value to be searched: ";
            cin >> n;                        // take value to search
            Node *ptr = head;                // start from first node
            while (ptr != NULL)              // traverse through list
            {            
                if (n == ptr->data) {        // if value found
                    found = 1;
                    cout << "\n✅ Value found at node " << position << ".";
                    break;                   // stop searching
                }
                ptr = ptr->next_addr;        // move to next node
                position++;                  // increase position
            }
            if (found == 0)                  // if not found
            {               
                cout << "\nValue doesn't exist in Linked list....";
            }
        }
    }

       
    // Function: getdata()
    // Purpose: Display all node values
    
    void getdata()
    {
        if (head == NULL)
        {                  // check if empty
            cout << "\nLinked List is Empty....";
        }
        else
        {
            Node *ptr = head;                // start from first node
            int n = 1;                       // for numbering nodes
            cout << "\nNodes in Linked List:\n";
            while (ptr != NULL) {            // traverse till end
                cout << n << " : " << ptr->data << endl;
                ptr = ptr->next_addr;        // go to next node
                n++;                         // increase index
            }
        }
    }
 
    // Function: update()
    // Purpose: Update a node’s value
    
    void update()
    {
        if (head == NULL)                   // check if list is empty
        {   
            cout << "\nLinked List is Empty....";
        } else
        {
            getdata();
            int n, found = 0;
            cout << "\nPlease Enter the value for Updation: ";
            cin >> n;                      // take old value to find
            Node *ptr = head;              // start from first node
            int position = 1;              // to track node number

            // traverse the list
            while (ptr != NULL)
            {
                if (n == ptr->data)        // value found
                {     
                    cout << "\nPlease enter new value: ";
                    cin >> ptr->data;      // update node value
                    found = 1;
                    cout << "\n✅ Value has been updated at node " << position << ".";
                    break;                 // stop searching
                }
                ptr = ptr->next_addr;      // move to next node
                position++;                // increment node counter
            }

            if (found == 0)              // value not found
            {              
                cout << "\nValue doesn't exist in Linked list....";
            }
        }
    }

    
    // Function: del()
    // Purpose: Delete a specific node
    
    void del()
    {
        if (head == NULL)                     // check if empty
        {                 
            cout << "\nLinked List is Empty....";
        }
        else
        {
            getdata();
            int n, found = 0, position = 1;
            cout << "\nPlease Enter the Node's value to delete: ";
            cin >> n;

            Node *ptr = head;                // pointer to current node
            Node *prev = NULL;               // pointer to previous node

            // traverse the list
            while (ptr != NULL)
            {
                if (ptr->data == n)
                {        // value found
                    found = 1;
                    if (prev == NULL)        // deleting first node
                    {     
                        head = ptr->next_addr;
                    } 
                    else                      // deleting middle or last node
                    {               
                        prev->next_addr = ptr->next_addr;
                    }
                    delete ptr;              // free memory
                    cout << "\nNode deleted successfully (was node " << position << ").";
                    break;
                }
                prev = ptr;                  // move prev to current
                ptr = ptr->next_addr;        // move current to next1
                position++;                  // update node counter
            }

            if (found == 0)                  // if not found
            {              
                cout << "\nValue doesn't exist in Linked list....";
            }
        }
    }
};


//  MAIN FUNCTION - Menu driven program

int main()
{
    Linked_list obj;                         // create linked list object
    int choice;                              // for user menu choice

    while (true)
    {                                        // infinite loop (until user exits)
        // show menu
        cout << "\n\n1 : Insert Node";
        cout << "\n2 : Count Nodes";
        cout << "\n3 : Search Node";
        cout << "\n4 : Update Node";
        cout << "\n5 : Delete Node";
        cout << "\n6 : Show Nodes";
        cout << "\n7 : Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;                       // input user choice

        // perform operation based on choice
        switch (choice)
        {
        case 1:
            obj.setdata();                   // call insert function
            break;
        case 2:
            obj.count();                     // call count function
            break;
        case 3:
            obj.search();                    // call search function
            break;
        case 4:
            obj.update();                    // call update function
            break;
        case 5:
            obj.del();                       // call delete function
            break;
        case 6:
            obj.getdata();                   // call display function
            break;
        case 7:
            exit(0);                         // exit program
        default:
            cout << "\nInvalid Choice..... Please try again.\n";
        }
    }
    return 0;                                // program ends
}