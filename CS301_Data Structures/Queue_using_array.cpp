#include<iostream>
using namespace std;

class Queue 
{
private:
    int front, rear, capacity;          //front = index of front element, rear = index of next insertion point , capacity = maximum size of queue
    int* arr;

public:

    // Constructor
    Queue(int c)    
    {
        front = rear = 0;
        capacity = c;
        arr = new int[capacity];            // dynamicallly allocate memory
    }

    // Enqueue operation
    void enqueue()    
    {
        if (rear == capacity)       // Queue full
        {
            cout << "Queue is Full\n";
            return;
        }

        int n;
        cout << "Enter value to enqueue: ";
        cin >> n;

        arr[rear++] = n;                        // Insert element at rear & increment rear           
        cout << n << " enqueued to queue\n";
    }

    // Dequeue operation
    void dequeue() 
    {
        if (front == rear)         // Queue empty
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << arr[front] << " dequeued from queue\n";
        front++;
    }

    // Display elements
    void display()                 
    {
        if (front == rear)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue elements are:\n";
        for (int i = front; i < rear; i++)
        {
            cout << arr[i] << "  ";
        }
    }

    // Size of queue
    void size()                     
    {
        cout << "Queue size is: " << rear - front << endl;     
    }

    // Search element
    void search()                           
    {
        if (front == rear)
        {
            cout << "Queue is Empty\n";
            return;
        }

        int n;
        cout << "Enter value to search: ";
        cin >> n;

        for (int i = front; i < rear; i++)
        {
            if (arr[i] == n)
            {
                cout << n << " found at position " << (i - front + 1) << "\n";     
                return;
            }
        }

        cout << n << " not found in queue\n";
    }

    // Update element
    void update(int oldVal, int newVal)   
    {
        if (front == rear)
        {
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = front; i < rear; i++)
        {
            if (arr[i] == oldVal)
            {
                arr[i] = newVal;
                cout << oldVal << " updated to " << newVal << "\n";
                return;
            }
        }

        cout << oldVal << " not found in queue\n";
    }   

    // Check empty
    void isEmpty()                  
    {
        if (front == rear)
            cout << "Queue is Empty\n";
        else
            cout << "Queue is not Empty\n";
    }   

    // Reverse the queue
    void reverse() 
    {
        if (front == rear)
        {
            cout << "Queue is Empty\n";
            return;
        }

        int start = front;
        int end = rear - 1;

        while (start < end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }

        cout << "Queue reversed\n";
    }

    // Clear queue
    void clear()                    
    {
        front = rear = 0;
        cout << "Queue cleared\n";
    }

    // Peek front element
    void peek()                    
    {
        if (front == rear)
            cout << "Queue is Empty\n";
        else
            cout << "Front element is: " << arr[front] << endl;
    }

    // Destructor
    ~Queue() 
    {
        delete[] arr;
    }
};

int main()
{
    int choice, oldVal, newVal;

    Queue q(10);   // create queue of size 10

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
                cout << "Enter old value and new value: ";
                cin >> oldVal >> newVal;
                q.update(oldVal, newVal);
                break;
            case 7: q.isEmpty(); break;
            case 8: q.reverse(); break;
            case 9: q.clear(); break;
            case 10: q.peek(); break;
            case 11: exit(0);
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
