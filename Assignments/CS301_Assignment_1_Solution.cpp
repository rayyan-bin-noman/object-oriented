#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

class Node {
private:
    string book;
    Node* next;
public:
    Node() : book(""), next(NULL) {}
    void setbook(string b) { book = b; }
    void setNext(Node* ptr) { next = ptr; }
    string getbook() const { return book; }
    Node* getNext() const { return next; }
};

// Stack Class implemented using Linked List
class Stack {
private:
    Node* top;          // points to top of stack
public:
    Stack() { top = NULL; }    

    // TODO 1: Implement the pushBook function
    void pushBook(string b) {                       	
        Node* newNode = new Node();
        newNode->setbook(b);
        newNode->setNext(top);
        top = newNode;
    }

    // TODO 2: Implement the popBook function
    string popBook() {                                  

        if (top == NULL) {
            cout << "Stack is empty, cannot pop.\n";
            return "";
        }
        string poppedBook = top->getbook();
        Node* temp = top;
        top = top->getNext();
        delete temp;
        return poppedBook;
    }

    // TODO 3: Implement the reverseBookStack fucntion (which reverse the entire stack)
    void reverseBookStack() {
        Node* prev = NULL;
        Node* current = top;
        Node* next = NULL;
        while (current != NULL) {
            next = current->getNext();
            current->setNext(prev);
            prev = current;
            current = next;
        }
        top = prev;
    }

    // TODO 4: Implement the displayBookStack function
    void displayBookStack() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Books in stack (top to bottom):\n";
        while (temp != NULL) {
            cout << temp->getbook() << endl;
            temp = temp->getNext();
        }
    }
};

int main() {
    // TODO 5: Write your VUID
    string studentID = "BC240200582"; 
    char lastDigitChar = studentID[studentID.length() - 1];
    int lastDigit = lastDigitChar - '0';

    Stack s;
    int booksToReshelve;

    cout << "--------------------------------\n";
    cout << "Library System - (" << studentID << ")\n";
    cout << "--------------------------------\n";
    cout << "Five Books added to Stack: (A-E Sequence)\n";

    // Write the code to push 5 books in satck here
    s.pushBook("Book-A");
    s.pushBook("Book-B");
    s.pushBook("Book-C");
    s.pushBook("Book-D");
    s.pushBook("Book-E");
    s.displayBookStack();
    cout << endl;

    // Reshelving/Poping books form stack based on your id last digit
    if (lastDigit <= 5)
        booksToReshelve = 2;
    else
        booksToReshelve = 3;

    cout << "VUID last digit is: " << lastDigit << ". Therefore, "
         << booksToReshelve << " Books popped/reshelved.\nUpdated Stack is:\n";

    for (int i = 0; i < booksToReshelve; i++) {
        s.popBook();
    }
    s.displayBookStack();
    cout << endl;

    // Reverse the remaining stack
    cout << "Reversing the stack:\n";
    s.reverseBookStack();

    // Displaying final stack
    cout << "Final stack after popping & reversing elements:\n";
    s.displayBookStack();

    return 0;
}
