#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next_addr;
    Node* pre_addr;
    Node(int v) : data(v), next_addr(nullptr), pre_addr(nullptr) {}
};

class Linked_list {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert node at the end
    void setdata() {
        int n;
        cout << "\nPlease Enter Value: ";
        cin >> n;

        Node* new_node = new Node(n);

        if (head == nullptr) {
            // first node in the list
            head = tail = new_node;
        } else {
            // append to tail
            tail->next_addr = new_node;
            new_node->pre_addr = tail;
            tail = new_node;
        }
        cout << "\nNew node inserted successfully....";
    }

    // Return number of nodes (does NOT print)
    int count() const {
        int c = 0;
        Node* ptr = head;
        while (ptr != nullptr) {
            ++c;
            ptr = ptr->next_addr;
        }
        return c;
    }

    // Search for a value and print its position (1-based)
    void search() const {
        if (head == nullptr) {
            cout << "\nLinked List is Empty....";
            return;
        }
        int n, position = 1;
        bool found = false;
        cout << "\nPlease Enter the value to be searched: ";
        cin >> n;

        Node* ptr = head;
        while (ptr != nullptr) {
            if (ptr->data == n) {
                cout << "\nValue found at node " << position << ".";
                found = true;
                break;
            }
            ptr = ptr->next_addr;
            ++position;
        }
        if (!found) {
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
        while (ptr != nullptr) {
            cout << idx << " : " << ptr->data << endl;
            ptr = ptr->next_addr;
            ++idx;
        }
    }

    // Display nodes backward using 'tail'
    void getdata_back() const {
        if (head == nullptr) {
            cout << "\nLinked List is Empty....";
            return;
        }
        Node* ptr = tail;
        int idx = count(); // count() does not print now
        cout << "\nNodes in Linked List (In Reverse Order):\n";
        while (ptr != nullptr) {
            cout << idx << " : " << ptr->data << endl;
            ptr = ptr->pre_addr;
            --idx;
        }
    }

    // Update first occurrence of a value
    void update() {
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
        while (ptr != nullptr) {
            if (ptr->data == oldVal) {
                cout << "\nPlease enter new value: ";
                cin >> ptr->data;
                cout << "\nValue has been updated at node " << position << ".";
                found = true;
                break;
            }
            ptr = ptr->next_addr;
            ++position;
        }
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

        while (ptr != nullptr) {
            if (ptr->data == n) {
                // Link previous node to next node (if prev exists)
                if (ptr->pre_addr != nullptr) {
                    ptr->pre_addr->next_addr = ptr->next_addr;
                } else {
                    // deleting head
                    head = ptr->next_addr;
                }

                // Link next node to previous node (if next exists)
                if (ptr->next_addr != nullptr) {
                    ptr->next_addr->pre_addr = ptr->pre_addr;
                } else {
                    // deleting tail
                    tail = ptr->pre_addr;
                }

                delete ptr;
                cout << "\nNode deleted successfully (was node " << position << ").";
                found = true;
                break;
            }
            ptr = ptr->next_addr;
            ++position;
        }

        if (!found) {
            cout << "\nValue doesn't exist in Linked list....";
        }
    }

    // optionally add destructor to free memory on program exit
    ~Linked_list() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next_addr;
            delete curr;
            curr = next;
        }
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
        cout << "\n6 : Show Forward Nodes";
        cout << "\n7 : Show Backward Nodes";
        cout << "\n8 : Exit";
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
            obj.getdata();                   // call forward display function
            break;
        case 7:
            obj.getdata_back();              // call backward display function
            break;
        case 8:
            exit(0);                         // exit program
        default:
            cout << "\nInvalid Choice..... Please try again.\n";
        }
    }
    
    return 0;                                // program ends
}