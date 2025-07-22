#include <iostream>
#include <string>
using namespace std;

class Event {
private:
    int eventID;
    string eventType;
    string eventName;

public:
    // Default Constructor
    Event() {
        eventID = 0;
        eventType = "";
        eventName = "";
    }

    // Parameterized Constructor
    Event(int ID, string Type, string Name) {
        eventID = ID;
        eventType = Type;
        eventName = Name;
    }

    // Copy Constructor
    Event(const Event &e) {
        eventID = e.eventID;
        eventType = e.eventType;
        eventName = e.eventName;
    }

    // Setter Functions
    void setEventId(int ID) {
        eventID = ID;
    }

    void setEventType(string Type) {
        eventType = Type;
    }

    void setEventName(string Name) {
        eventName = Name;
    }

    // Getter Functions
    int getEventId() {
        return eventID;
    }

    string getEventType() {
        return eventType;
    }

    string getEventName() {
        return eventName;
    }

    // Display Function
    void display() {
        cout << "Event ID: " << eventID << endl;
        cout << "Event Type: " << eventType << endl;
        cout << "Event Name: " << eventName << endl;
    }
}; 

int main() { 
    Event event1(101, "Conference", "Tech Innovations"); 
     
    Event event2 = event1; 
     
    Event event3; 
    event3.setEventId(202); 
    event3.setEventType("Corporate Party"); 
    event3.setEventName("Annual Celebration"); 
     
    cout << "Event 1 Details:\n"; 
    event1.display(); 
    cout << "\nEvent 2 (Copied from Event 1):\n"; 
    event2.display(); 
     
    cout << "\nAccessing Event 3 details using getters:\n"; 
    cout << "Event ID: " << event3.getEventId() << endl; 
    cout << "Event Type: " << event3.getEventType() << endl; 
    cout << "Event Name: " << event3.getEventName() << endl; 
    return 0; 
} 
