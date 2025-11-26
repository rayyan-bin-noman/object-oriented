#include<iostream>
using namespace std;

// Node structure
class Node 
{
public:
    int data;
    Node* next;

    Node(int val)               // Constructor to initialize node
    {
        data = val;             
        next = nullptr;
    }
};

// Queue class using Linked List
class Queue 
{
private:
    Node* front;                // Pointer to front node
    Node* rear;                 // Pointer to rear node

public:

    // Constructor
    Queue() 
    {
        front = rear = nullptr;
    }

    // --- Reusable Sorting Function ---
    // Smaller value = Higher priority
    void Sort_Queue()
    {
        if (front == nullptr || front->next == nullptr)
            return; // No need to sort if queue is empty or has one element

        bool swapped;
        do 
        {
            swapped = false;
            Node* curr = front;
            Node* prev = nullptr;

            while (curr->next != nullptr) 
            {
                if (curr->data > curr->next->data) 
                {
                    // Swap data
                    swap(curr->data, curr->next->data);
                    swapped = true;
                }
                prev = curr;
                curr = curr->next;
            }
        } while (swapped);
    }

    // Enqueue operation
    void enqueue() 
    {
        int n;
        cout << "Enter value to enqueue: ";
        cin >> n;

        Node* newNode = new Node(n);        

        if (rear == nullptr)           // Queue empty
        {       
            front = rear = newNode;    // Both front and rear point to new node
        }
        else 
        {
            rear->next = newNode;    // Link at end
            rear = newNode;          // Move rear
        }

        Sort_Queue();         // sort the queue
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

        Node* temp = front;         // Store front node
        cout << temp->data << " dequeued from queue\n";

        front = front->next;        // Move front to next node  

        if (front == nullptr)         // If queue becomes empty
            rear = nullptr;         // Update rear to nullptr

        delete temp;            // Free memory  
    }

    // Display queue
    void display() 
    {
        if (front == nullptr) 
        {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;
        cout << "Sorted queue elements:\n";
        while (temp != nullptr) 
        {
            cout << temp->data << "  ";
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
    void update() 
    {
        // If queue is empty
        if (front == nullptr) 
        {
            cout << "Queue is Empty\n";
            return;
        }

        int oldVal, newVal;
        cout << "Enter old value: ";
        cin >> oldVal;
        cout << "Enter new value: ";
        cin >> newVal;

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
            Sort_Queue();         // sort the queue
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

    // Clear queue
    void clear() 
    {
        Node* temp;

        while (front != nullptr) 
        {
            temp = front;               // Store front node 
            front = front->next;        // Move front to next node
            delete temp;                // Free memory
        }

        rear = nullptr;              // Set rear to nullptr

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
    int choice;

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
        cout << "8. Clear\n";
        cout << "9. Peek\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: q.enqueue(); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: q.size(); break;
            case 5: q.search(); break;
            case 6: q.update(); break;
            case 7: q.isEmpty(); break;
            case 8: q.clear(); break;
            case 9: q.peek(); break;
            case 10 : exit(0);
            default: cout << "Invalid choice\n";
        }
    }

    return 0;
}
