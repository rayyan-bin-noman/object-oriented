#include <iostream>
#include <string>
using namespace std;

// Class representing a single Visitor Node
class Visitor {
public:
    int id;
    string name;
    string category; // VIP or Normal
    Visitor* next;

    Visitor(int vId, string vName, string vCategory) {
        id = vId;
        name = vName;
        category = vCategory;
        next = NULL;
    }
};

// Queue class using linked list implementation
class Queue {
private:
    Visitor* front;
    Visitor* rear;

public:
    Queue() {
        front = rear = NULL;
    }
	
	// TODO 1: Implement the enqueueVisitor() function
    void enqueueVisitor(int id, string name, string category) {
        
        // Write your code here (to insert the visitors in the queue....)
        Visitor* newNode = new Visitor(id, name, category);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }
	
	// TODO 2: Implement the dequeueVisitor() function
    void dequeueVisitor() {
        // Write your code here (to remove from the queue....)
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        Visitor* temp = front;
        cout << "Serving: " << temp->name << " (ID: " << temp->id << ") from " 
             << temp->category << " Queue\n";

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }
	
	// TODO 3: Implement the displayVisitor() function
    void displayVisitor(const string &title) {
        // Write your code here (to display the list of visitors....)
        cout << "\n" << title << ":\n";

        Visitor* temp = front;

        if (temp == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        while (temp != NULL) {
            cout << "ID: " << temp->id 
                 << " | Name: " << temp->name 
                 << " | Category: " << temp->category << endl;
            temp = temp->next;
        }
    }

    // TODO 4: Implement the RemoveByIdVisitor() function
    bool removeByIdVisitor(int id) {
       // Write your code here (to remove the visitor from the queue by Id....) 

        // Case 1: Visitor at front
        if (front != NULL && front->id == id) {
            Visitor* del = front;
            front = front->next;
            if (front == NULL) rear = NULL;
            delete del;
            cout << "Visitor with ID " << id << " removed successfully.\n";
            return true;
        }
        
        // Case 2: Search in middle or end
        Visitor* prev = front;
        Visitor* curr = (front != NULL ? front->next : NULL);

        while (curr != NULL) {
            if (curr->id == id) {
                prev->next = curr->next;
                if (curr == rear) rear = prev;
                delete curr;
                cout << "Visitor with ID " << id << " removed successfully.\n";
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
       
	    // If visitor not found
        return false;
    }
    
    bool isEmpty() {
        return front == NULL;
    }

    int count() {
        int total = 0;
        Visitor* temp = front;
        while (temp != NULL) {
            total++;
            temp = temp->next;
        }
        return total;
    }
};

int main() {
    // TODO 5: Write your VUID
    string studentID = "BC240200582";  // Replace BC123456789 with your VUID. 
    cout << "Student Id: "<< studentID << "\n";
    cout << "Hospital Visitor Queue Management System\n";
    Queue vip, normal;
    vip.enqueueVisitor(201, "Ali", "VIP");
    vip.enqueueVisitor(202, "Sara", "VIP");
    normal.enqueueVisitor(203, "Ahmed", "Normal");
    normal.enqueueVisitor(204, "Zain", "Normal");
    vip.enqueueVisitor(205, "Zara", "VIP");

    // Display current queues
    vip.displayVisitor("VIP Visitor Queue");
    normal.displayVisitor("Normal Visitor Queue");

    // Serve visitors automatically
    cout << "\n--- Serving Visitors Automatically ---\n";
    if (!vip.isEmpty()) vip.dequeueVisitor();
    if (!vip.isEmpty()) vip.dequeueVisitor();
    if (!vip.isEmpty()) vip.dequeueVisitor();
	if (!normal.isEmpty()) normal.dequeueVisitor();
    if (!normal.isEmpty()) normal.dequeueVisitor();

    // Remove visitor by ID
    cout << "\n--- Removing Visitor ID 204 (if exists) ---\n";
    if (!vip.removeByIdVisitor(204) && !normal.removeByIdVisitor(204))
        cout << "Visitor not found for removal.\n";

    // Total visitors remaining
    int total = vip.count() + normal.count();
    cout << "\nTotal Visitors Remaining: " << total << endl;

    return 0;
}
