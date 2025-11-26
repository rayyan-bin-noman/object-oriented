#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    int capacity;
    int size;
    int* arr;

public:

    // Constructor
    PriorityQueue(int c)
    {
        capacity = c;
        size = 0;
        arr = new int[capacity];
    }

    // --- Reusable Sorting Function ---
    // Smaller value = Higher priority
    void sortQueue()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Enqueue element (insert + sort)
    void enqueue()
    {
        if (size == capacity)
        {
            cout << "Queue is Full\n";
            return;
        }

        int val;
        cout << "Enter value to enqueue: ";
        cin >> val;

        arr[size++] = val;   // place at end
        sortQueue();         // sort the queue

        cout << val << " enqueued with priority\n";
    }

    // Dequeue highest priority (smallest value)
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << arr[0] << " dequeued (highest priority)\n";

        // shift all elements left
        for (int i = 1; i < size; i++)
            arr[i - 1] = arr[i];

        size--;
    }

    // Display queue
    void display()
    {
        if (size == 0)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Priority Queue elements:\n";
        for (int i = 0; i < size; i++)
            cout << arr[i] << "  ";
    }

    // Search element
    void search()
    {
        if (size == 0)
        {
            cout << "Queue is Empty\n";
            return;
        }

        int val;
        cout << "Enter value to search: ";
        cin >> val;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == val)
            {
                cout << val << " found at position " << i + 1 << endl;      //i+1 = real position (1-based index)
                return;
            }
        }

        cout << val << " not found\n";
    }

    // Update element and re-sort queue
    void update()
    {
        if (size == 0)
        {
            cout << "Queue is Empty\n";
            return;
        }

        int oldVal, newVal;
        cout << "Enter old value and new value: ";
        cin >> oldVal >> newVal;

        bool found = false;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == oldVal)
            {
                arr[i] = newVal; 
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << oldVal << " not found\n";
            return;
        }

        sortQueue(); // maintain priority after update
        cout << "Updated successfully\n";
    }

    void clear()
    {
        size = 0;
        cout << "Queue cleared\n";
    }

    void peek()
    {
        if (size == 0)
            cout << "Queue is Empty\n";
        else
            cout << "Highest priority element: " << arr[0] << endl;
    }

    void isEmpty()
    {
        if (size == 0)
            cout << "Queue is Empty\n";
        else
            cout << "Queue is not Empty\n";
    }

    void getSize()
    {
        cout << "Queue size: " << size << endl;
    }

    // Destructor
    ~PriorityQueue()
    {
        delete[] arr;
    }
};

int main()
{
    PriorityQueue q(10);
    int choice;

    while (true)
    {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Update\n";
        cout << "6. Peek\n";
        cout << "7. Size\n";
        cout << "8. Is Empty\n";
        cout << "9. Clear\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: q.enqueue(); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: q.search(); break;
            case 5: q.update(); break;
            case 6: q.peek(); break;
            case 7: q.getSize(); break;
            case 8: q.isEmpty(); break;
            case 9: q.clear(); break;
            case 10: exit(0);
            default: cout << "Invalid choice\n";
        }
    }

    return 0;
}
