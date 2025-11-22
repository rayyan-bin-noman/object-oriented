#include<iostream>
#include<string>
int top = -1;
const int MAX = 100;    
using namespace std;
class Stack 
{
private:
    int arr[MAX];
public:
    void push()
    {
        if (top >= MAX - 1)                 // stack overflow
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            int n;
            cout << "Enter value to push: ";
            cin >> n;                            // take value from user
            arr[++top] = n;                     // push element onto stack
            cout << n << " pushed to stack\n";
        }
    }
    void pop() 
    {
        if (top < 0)                        // stack underflow
        {
            cout << "Stack Underflow\n";
        }
        else
        {
            cout << arr[top--] << " popped from stack\n";       // pop element from stack
        }
    }
    void peek()                     // view top element
    {
        if (top < 0)                        // stack is empty
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            cout << "Top element is: " << arr[top] << endl;    // show top element
        }
    }
    void display()                 // display all stack elements
    {
        if (top < 0)                        // stack is empty
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            cout << "Stack elements are:\n";
            for (int i = top; i >= 0; i--)   // print from top to bottom
            {
                cout << arr[i] << endl;
            }
        }
    }
    void size()                     // display stack size
    {
        cout << "Stack size is: " << top + 1 << endl;   // size is top index + 1
    }
    void search()                           // search for an element
    {
        if (top < 0)                        // stack is empty
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            int n;
            int found = 0;
            cout << "Enter value to search: ";  
            cin >> n;                        // take value to search
            for (int i = top; i >= 0; i--)      // search from top to bottom
            {
                if (arr[i] == n)
                {
                    cout << n << " found at position " << top - i + 1 << " from top\n";     // top - i + 1 = distance from top
                    found++;
                    break;
                }
            }
            if (found == 0)
            cout << n << " not found in stack\n";           // element not found
        }
    }
    void update(int oldVal, int newVal)   // update an element
    {
        if (top < 0)                        // stack is empty
        {
            cout << "Stack is Empty\n";
        }
        int found;
        for (int i = top; i >= 0; i--)      // search from top to bottom
        {
            if (arr[i] == oldVal)
            {
                arr[i] = newVal;                // update value
                cout << oldVal << " updated to " << newVal << "\n";
                found++;
            }
        }
        if (found == 0)
        cout << oldVal << " not found in stack\n";          // element not found
    }
    void isEmpty()                  // check if stack is empty
    {
        if (top < 0)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            cout << "Stack is not Empty\n";
        }
    }
    void reverse()                  // reverse the stack
    {
        if (top < 0)                        // stack is empty
        {
            cout << "Stack is Empty\n";
        }
        int start = 0;
        int end = top;
        while (start < end)                 // swap elements from start and end
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        cout << "Stack reversed\n";
    }
    void clear()                    // clear the stack
    {
        top = -1;                           // reset top index
        cout << "Stack cleared\n";
    }

};

int main()
{
    Stack s;
    int choice, value, oldVal, newVal;
    while (true)        
    {
        system("cls");
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Size\n";
        cout << "6. Search\n";
        cout << "7. Update\n";
        cout << "8. Is Empty\n";
        cout << "9. Reverse\n";
        cout << "10. Clear\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                s.size();
                break;
            case 6:
                s.search();
                break;
            case 7:
                cout << "Enter old value to update: ";
                cin >> oldVal;
                cout << "Enter new value: ";
                cin >> newVal;
                s.update(oldVal, newVal);
                break;
            case 8:
                s.isEmpty();
                break;
            case 9:
                s.reverse();
                break;
            case 10:
                s.clear();
                break;
            case 11:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}