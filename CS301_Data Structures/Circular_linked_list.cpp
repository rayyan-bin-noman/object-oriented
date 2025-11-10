#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next_addr;
    Node(int v) : data(v), next_addr(nullptr) {}
};

class Linked_list 
{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert node at the end
    void setdata() {
        int n;
        cout << "\nPlease Enter Value: ";
        cin >> n;

        Node* new_node = new Node(n);

        if (head == nullptr) 
        {
            // first node in the list
            head = tail = new_node;
            new_node->next_addr = new_node; // point to itself
        } 
        else 
        {
            // append to tail
            tail->next_addr = new_node;
            tail = new_node;
            tail->next_addr = head; // make it circular again   
        }
        cout << "\nNew node inserted successfully....";
    }

    // Return number of nodes (does NOT print)
    int count() const 
    {
        if (head == nullptr) 
        {                  
            cout << "\nLinked List is Empty....";
            return 0;
        }

        int c = 0;
        Node* ptr = head;
        do
        {
            ++c;
            ptr = ptr->next_addr;
        
        } while (ptr != head);

        return c;
    }

    // Search for a value and print its position (1-based)
    void search() const {
        if (head == nullptr) 
        {                  
            cout << "\nLinked List is Empty....";
            return;
        }
        int n, position = 1;
        bool found = false;
        cout << "\nPlease Enter the value to be searched: ";
        cin >> n;

        Node* ptr = head;
        do 
        {
            if (ptr->data == n) 
            {
                cout << "\nValue found at node " << position << ".";
                found = true;
                break;
            }
            ptr = ptr->next_addr;
            ++position;
        
        } while (ptr != head);

        if (!found) 
        {
            cout << "\nValue doesn't exist in Linked list...."; 
        }
    }

    // Display nodes forward
    void getdata() const {
        if (head == nullptr) {
            cout << "\nLinked List is Empty....";
            return;
        }
        Node* ptr = head;
        int idx = 1;
        cout << "\nNodes in Linked List:\n";
        do 
        {
            cout << idx << " : " << ptr->data << endl;
            ptr = ptr->next_addr;
            ++idx;
        
        } while (ptr != head);
    }

    // Update first occurrence of a value
    void update() 
    {
        if (head == nullptr) {
            cout << "\nLinked List is Empty....";
            return;
        }
        getdata(); // optional: show list before update
        int oldVal;
        cout << "\nPlease Enter the value for Updation: ";
        cin >> oldVal;

        Node* ptr = head;
        int position = 1;
        bool found = false;
        
        do                              //avoiding infinite while loop in circular list
        {
            if (ptr->data == oldVal) 
            {
                cout << "\nPlease enter new value: ";
                cin >> ptr->data;
                cout << "\nValue has been updated at node " << position << ".";
                found = true;
                break;
            }
            ptr = ptr->next_addr;
            ++position;
        
        } while (ptr != head);

        if (!found) {
            cout << "\nValue doesn't exist in Linked list....";
        }
    }

    // Delete first occurrence of value n
    void del() {
        if (head == nullptr) {
            cout << "\nLinked List is Empty....";
            return;
        }

        getdata(); // optional: show list before deletion

        int n;
        cout << "\nPlease Enter the Node's value to delete: ";
        cin >> n;

        Node* ptr = head;
        int position = 1;
        bool found = false;

        do                                      //avoiding infinite while loop in circular list
        {
            if (ptr->data == n) 
            {
                //Case 1: Deleting the only node
                if (head == tail && ptr == head) 
                {
                    delete ptr;
                    head = tail = nullptr;
                    cout << "\nNode deleted successfully (list is now empty).";
                    found = true;
                    return;                          // stop function safely
                }
                //Case 2: Deleting 1st / head node
                else if (ptr == head) 
                {
                    head = head->next_addr;
                    tail->next_addr = head;
                    delete ptr;
                }
                //Case 3: Deleting last / tail node
                else if (ptr == tail) 
                {
                    Node* temp = head;
                    while (temp->next_addr != tail)     // find 2nd last node
                    {
                        temp = temp->next_addr;
                    }   
                    temp->next_addr = head;             // maintain circular link
                    tail = temp;                        // update tail
                    delete ptr;                         // delete old tail
                }
                //Case 4: Deleting middle node
                else 
                {
                    Node* temp = head;
                    while (temp->next_addr != ptr)     // find previous node
                    {
                        temp = temp->next_addr;
                    }
                    temp->next_addr = ptr->next_addr;  // bypass the node to delete
                    delete ptr;
                }

                cout << "\nNode deleted successfully (was node " << position << ").";
                found = true;
                break;                          // stop after deletion
            }

            ptr = ptr->next_addr;
            ++position;

        } while (ptr != head);                  // traverse until we circle back to head

        if (!found) 
        {
            cout << "\nValue doesn't exist in Linked list....";
        }
    }

    // optionally add destructor to free memory on program exit
    ~Linked_list() 
    {
        if (head == nullptr) return;            // prevent crash when list is empty

        Node* curr = head;
        do
        {
            Node* next = curr->next_addr;
            delete curr;
            curr = next;
        
        } while (curr != head);

        head = tail = nullptr;
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
            cout << "\nTotal Nodes: " << obj.count();      // call count function
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
    
    return 0;                                // program ends
}