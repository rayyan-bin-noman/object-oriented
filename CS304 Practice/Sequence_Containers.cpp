#include <iostream>     // For standard I/O
#include <string>       // For string (optional here)
#include <vector>       // For vector
#include <deque>        // For deque
#include <list>         // For list

using namespace std;

// -------------------------------------------------------------
// | Concept       | Description                                                            |
// | ------------- | ----------------------------------------------------------------------- |
// | vector<int>   | Dynamic array of integers.                                              |
// | push_back()   | Adds to end.                                                           |
// | capacity()    | Memory reserved (may be greater than actual size).                     |
// | size()        | Actual number of elements.                                              |
// | list<float>   | Doubly linked list allowing fast insertion/removal at any position.     |
// | deque<int>    | Double-ended queue – can insert/remove from both front and back.       |
// -------------------------------------------------------------

int main()
{ 
    // ==========================
    // VECTOR EXAMPLE
    // ==========================
    vector<int> iv;   // Dynamic array to store integers
    int x, y;
    char ch;

    do { 
        cout << "Enter the first integer: ";
        cin >> x;
        cout << "Enter the second integer: ";
        cin >> y;

        iv.push_back(x);
        iv.push_back(y);

        cout << "Current capacity of iv = " << iv.capacity() << endl;
        cout << "Current size of iv = " << iv.size() << endl;

        // Display contents of vector
        cout << "Current vector contents: ";
        for (int val : iv)
            cout << val << " ";
        cout << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> ch;

    } while (ch == 'y');

    // ==========================
    // LIST EXAMPLE
    // ==========================
    list<float> _list;

    _list.push_back(7.8);   // [7.8]
    _list.push_back(8.9);   // [7.8, 8.9]

    list<float>::iterator it = _list.begin();  // Point to beginning
    _list.insert(++it, 5.3);  // Insert 5.3 after 7.8 → [7.8, 5.3, 8.9]

    // Display contents of list
    cout << "\nContents of list after insertion: ";
    for (float val : _list)
        cout << val << " ";
    cout << endl;

    // ==========================
    // DEQUE EXAMPLE
    // ==========================
    deque<int> dq;

    dq.push_front(3);  // [3]
    cout << "\nAfter push_front(3): ";
    for (int val : dq)
        cout << val << " ";
    cout << endl;

    dq.push_back(5);   // [3, 5]
    cout << "After push_back(5): ";
    for (int val : dq)
        cout << val << " ";
    cout << endl;

    dq.pop_front();    // Remove 3 → [5]
    cout << "After pop_front(): ";
    for (int val : dq)
        cout << val << " ";
    cout << endl;

    dq.pop_back();     // Remove 5 → []
    cout << "After pop_back(): ";
    
    if (dq.empty())
        cout << "[empty]";
    else
        for (int val : dq)
            cout << val << " ";
    cout << endl;

    return 0;
}
