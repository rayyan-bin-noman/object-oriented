#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class LibraryMember {
protected:
    int memberId;
    string memberName;
    float membershipFee;

public:
    LibraryMember(int id, string name) : memberId(id), memberName(name), membershipFee(0.0) {}
    virtual void calculateMembershipFee() = 0;
    virtual void displayDetails() const = 0;
    virtual ~LibraryMember() {
        // Destructor
    }
};

// StudentMember Class
class StudentMember : public LibraryMember {
private:
    float baseFee;
    float discount;

public:
    StudentMember(int id, string name, float base, float disc)
        : LibraryMember(id, name), baseFee(base), discount(disc) {}

    void calculateMembershipFee() override {
        membershipFee = baseFee - discount;
    }

    void displayDetails() const override {
        cout << "=== Student Member ===" << endl;
        cout << "ID: " << memberId << endl;
        cout << "Name: " << memberName << endl;
        cout << "Base Fee: " << baseFee << endl;
        cout << "Discount: " << discount << endl;
        cout << "Membership Fee: " << membershipFee << endl;
        cout << endl;
    }

    ~StudentMember() {
        // Destructor
    }
};

// FacultyMember Class
class FacultyMember : public LibraryMember {
private:
    float baseFee;
    float facilityFee;

public:
    FacultyMember(int id, string name, float base, float facility)
        : LibraryMember(id, name), baseFee(base), facilityFee(facility) {}

    void calculateMembershipFee() override {
        membershipFee = baseFee + facilityFee;
    }

    void displayDetails() const override {
        cout << "=== Faculty Member ===" << endl;
        cout << "ID: " << memberId << endl;
        cout << "Name: " << memberName << endl;
        cout << "Base Fee: " << baseFee << endl;
        cout << "Facility Fee: " << facilityFee << endl;
        cout << "Membership Fee: " << membershipFee << endl;
        cout << endl;
    }

    ~FacultyMember() {
        // Destructor
    }
};

int main() {
    cout << "===== Membership Detail =====\n" << endl;

    // Creating dynamic array of base class pointers
    LibraryMember* members[2];

    // Creating one StudentMember and one FacultyMember
    members[0] = new StudentMember(101, "ABC", 5000, 1000);
    members[1] = new FacultyMember(201, "XYZ", 7000, 2000);

    // Polymorphic calls
    for (int i = 0; i < 2; ++i) {
        members[i]->calculateMembershipFee();
        members[i]->displayDetails();
    }

    // Deleting objects
    for (int i = 0; i < 2; ++i) {
        delete members[i];
    }

    return 0;
}