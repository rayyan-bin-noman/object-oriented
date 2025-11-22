#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* next;

public:
    // Input-based setter
    void setdata()
    {
        cout << "\nPlease Enter the value: ";
        cin >> data;
    }

    // Direct setter for update()
    void setdata(int val)
    {
        data = val;
    }

    int getdata()
    {
        return data;
    }

    void setnext(Node* ptr)
    {
        next = ptr;
    }

    Node* getnext()
    {
        return next;
    }
};

class Stack
{
private:
    Node* head = nullptr; // top of stack

public:
    // PUSH OPERATION
    void push()
    {
        Node* current = new Node;
        current->setdata();      // take input
        current->setnext(head);  // point new node to old head
        head = current;          // update head

        cout << current->getdata() << " pushed to stack\n";
    }

    // POP OPERATION
    void pop()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }

        Node* ptr = head;
        head = head->getnext();
        cout << ptr->getdata() << " popped from stack\n";
        delete ptr;
    }

    // DISPLAY STACK
    void display()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }

        Node* ptr = head;
        cout << "Stack elements are:\n";
        while (ptr != nullptr)
        {
            cout << ptr->getdata() << endl;
            ptr = ptr->getnext();
        }
    }

    // SIZE OF STACK
    void size()
    {
        int count = 0;
        Node* ptr = head;       // start from top

        while (ptr != nullptr)
        {
            count++;
            ptr = ptr->getnext();
        }

        cout << "Stack size: " << count << endl;
    }

    // SEARCH ELEMENT
    void search()
    {
        if (head == nullptr)
        {
            cout << "Stack is Empty\n";
            return;
        }

        int val;
        cout << "Enter value to search: ";
        cin >> val;

        Node* ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->getdata() == val)
            {
                cout << val << " found in stack\n";
                return;
            }
            ptr = ptr->getnext();
        }

        cout << val << " not found in stack\n";
    }

    // UPDATE ELEMENT
    void update(int oldVal, int newVal)
    {
        if (head == nullptr)
        {
            cout << "Stack is Empty\n";
            return;
        }

        Node* ptr = head;

        while (ptr != nullptr)
        {
            if (ptr->getdata() == oldVal)
            {
                ptr->setdata(newVal);  // directly set
                cout << oldVal << " updated to " << newVal << "\n";
                return;
            }
            ptr = ptr->getnext();
        }

        cout << oldVal << " not found in stack\n";
    }

    // CHECK FOR EMPTY STACK
    void isEmpty()
    {
        if (head == nullptr)
            cout << "Stack is Empty\n";
        else
            cout << "Stack is not Empty\n";
    }

    // REVERSE STACK
    void reverse()
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr)
        {
            next = current->getnext();          // store next node
            current->setnext(prev);             // reverse current node's pointer
            prev = current;                     // move pointers one position ahead
            current = next;                     // move to next node
        }

        head = prev;                            // update head to new top
        cout << "Stack reversed\n";
    }

    // CLEAR STACK
    void clear()
    {
        while (head != nullptr)
        {
            Node* ptr = head;
            head = head->getnext();
            delete ptr;
        }

        cout << "Stack cleared\n";
    }

    // PEEK OPERATION (top element)
    void peek()
    {
        if (head == nullptr)
            cout << "Stack is empty\n";
        else
            cout << "Top element is: " << head->getdata() << endl;
    }
};

int main()
{
    Stack s;
    int choice, oldVal, newVal;

    while (true)
    {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Size\n5. Search\n6. Update\n7. Is Empty\n8. Reverse\n9. Clear\n10. Peek\n11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: s.push(); break;
            case 2: s.pop(); break;
            case 3: s.display(); break;
            case 4: s.size(); break;
            case 5: s.search(); break;
            case 6:
                cout << "Enter old value and new value: ";
                cin >> oldVal >> newVal;
                s.update(oldVal, newVal);
                break;
            case 7: s.isEmpty(); break;
            case 8: s.reverse(); break;
            case 9: s.clear(); break;
            case 10: s.peek(); break;
            case 11: exit(0);
            default: cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
