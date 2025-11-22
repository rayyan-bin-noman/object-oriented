#include<iostream>
using namespace std;

// Node structure
class Node 
{
public:
    int data;
    Node* next;

    Node(int val) 
    {
        data = val;
        next = nullptr;
    }
};

// Queue class using Linked List
class Queue 
{
private:
    Node* front;
    Node* rear;

public:

    // Constructor
    Queue() 
    {
        front = rear = nullptr;
    }

    // Enqueue operation
    void enqueue() 
    {
        int n;
        cout << "Enter value to enqueue: ";
        cin >> n;

        Node* newNode = new Node(n);

        if (rear == nullptr) {       // Queue empty
            front = rear = newNode;
        }
        else {
            rear->next = newNode;    // Link at end
            rear = newNode;          // Move rear
        }

        cout << n << " enqueued to queue\n";
    }

    // Dequeue operation
    void dequeue() 
    {
        if (front == nullptr)                // Queue empty
        {                           
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " dequeued from queue\n";

        front = front->next;

        if (front == nullptr)         // If queue becomes empty
            rear = nullptr;

        delete temp;
    }

    // Display queue
    void display() 
    {
        if (front == nullptr) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements:\n";
        while (temp != nullptr) 
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // Size of queue
    void size() 
    {
        int count = 0;
        Node* temp = front;

        while (temp != nullptr) 
        {
            count++;
            temp = temp->next;
        }

        cout << "Queue size is: " << count << endl;
    }

    // Search in queue
    void search() 
    {
        if (front == nullptr) 
        {
            cout << "Queue is Empty\n";
            return;
        }

        int n, pos = 1;
        cout << "Enter value to search: ";
        cin >> n;

        Node* temp = front;

        while (temp != nullptr) 
        {
            if (temp->data == n) 
            {
                cout << n << " found at position " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        }

        cout << n << " not found in queue\n";
    }

    // Update element
    void update(int oldVal, int newVal) 
    {
        if (front == nullptr) 
        {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;
        while (temp != nullptr) 
        {
            if (temp->data == oldVal) 
            {
                temp->data = newVal;
                cout << oldVal << " updated to " << newVal << endl;
                return;
            }
            temp = temp->next;
        }

        cout << oldVal << " not found in queue\n";
    }

    // Check empty
    void isEmpty() 
    {
        if (front == nullptr)
            cout << "Queue is Empty\n";
        else
            cout << "Queue is not Empty\n";
    }

    // Reverse queue
    void reverse() 
    {
        if (front == nullptr) 
        {
            cout << "Queue is Empty\n";
            return;
        }

        Node* prev = nullptr;
        Node* curr = front;
        Node* next = nullptr;

        rear = front;   // After reversing, old front becomes rear

        while (curr != nullptr) 
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        front = prev;

        cout << "Queue reversed\n";
    }

    // Clear queue
    void clear() 
    {
        Node* temp;

        while (front != nullptr) 
        {
            temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;

        cout << "Queue cleared\n";
    }

    // Peek front
    void peek() 
    {
        if (front == nullptr)
            cout << "Queue is Empty\n";
        else
            cout << "Front element is: " << front->data << endl;
    }

    // Destructor
    ~Queue() 
    {
        clear();
    }
};

int main() 
{
    int choice, oldVal, newVal;

    Queue q;

    while (true) 
    {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Size\n";
        cout << "5. Search\n";
        cout << "6. Update\n";
        cout << "7. Is Empty\n";
        cout << "8. Reverse\n";
        cout << "9. Clear\n";
        cout << "10. Peek\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: q.enqueue(); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: q.size(); break;
            case 5: q.search(); break;
            case 6:
                cout << "Enter old value & new value: ";
                cin >> oldVal >> newVal;
                q.update(oldVal, newVal);
                break;
            case 7: q.isEmpty(); break;
            case 8: q.reverse(); break;
            case 9: q.clear(); break;
            case 10: q.peek(); break;
            case 11: exit(0);
            default: cout << "Invalid choice\n";
        }
    }

    return 0;
}
