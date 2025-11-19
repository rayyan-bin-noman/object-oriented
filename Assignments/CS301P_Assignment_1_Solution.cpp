/*
    Name: Rayyan Bin Noman
    VU ID: BC240200582
    Course: CS301P – Data Structures (Practical)
    Assignment No. 1 – Fall 2025
    Topic: Parking Lot Management System using Stack (Linked List)
*/

#include <iostream>
#include <string>
using namespace std;

// Each node represents one car in the parking area
class CarNode 
{
public:
    string carNumber;   // car number or ID
    CarNode* next;      // pointer to next node

    CarNode(string number) 
    {
        carNumber = number;
        next = NULL;
    }
};

// Stack class implemented using singly linked list
class ParkingStack 
{
private:
    CarNode* top;   // pointer to top (last parked car)
public:
    ParkingStack() 
    {
        top = NULL;
    }

    // Function to add (push) a new car
    void parkCar(string carNumber) 
    {
        CarNode* newCar = new CarNode(carNumber);
        newCar->next = top;  // link the new car to the previous top
        top = newCar;        // update top pointer
        cout << "Car " << carNumber << " parked successfully.\n";
    }

    // Function to remove (pop) the last parked car
    void removeCar() 
    {
        if (top == NULL) 
        {
            cout << "No cars to remove. Parking area is empty.\n";
            return;
        }
        CarNode* temp = top;
        cout << "Car " << top->carNumber << " is leaving the parking.\n";
        top = top->next;
        delete temp;
    }

    // Function to display all parked cars from top to bottom
    void displayParkedCars() 
    {
        if (top == NULL) 
        {
            cout << "Parking area is empty.\n";
            return;
        }

        cout << "\nCurrently parked cars (Top to Bottom):\n";
        int position = 1;
        CarNode* temp = top;
        while (temp != NULL) 
        {
            cout << "Car#" << position << ": " << temp->carNumber << endl;
            temp = temp->next;
            position++;
        }
    }
    // Destructor to clean up memory
    ~ParkingStack() 
    {
        while (top != NULL) removeCar();
    }
};

int main() 
{
    cout << "------------------------------------------\n";
    cout << "Parking Lot Management System\n";
    cout << "Developed by: Rayyan Bin Noman (VUID: BC240200582)\n";
    cout << "------------------------------------------\n\n";

    ParkingStack parking;

    // Step 1: Auto-park car using last 4 digits of VUID
    string myCar = "0582"; // last 4 digits of BC240200582
    cout << "Auto-parking VUID car number: " << myCar << endl;
    parking.parkCar(myCar);

    // Step 2: Park two more cars
    parking.parkCar("PAK-301");
    parking.parkCar("PAK-301P");

    // Step 3: Remove (pop) last parked car
    cout << "\nPerforming pop operation (last car leaves):\n";
    parking.removeCar();

    // Step 4: Display all remaining cars
    parking.displayParkedCars();

    cout << "\nProgram ended successfully.\n";
    return 0;
}
