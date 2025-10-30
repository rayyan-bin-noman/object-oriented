#include<iostream>
#include<string>
using namespace std;

class base
{
public:
    void displayname()
    {
        cout << "\nMy name is Rayyan";
    }

    virtual void displayMarks() = 0;  // Pure virtual function
};

class derived : public base
{
public:
    void displayRollNo()
    {
        cout << "\nMy Roll No is: BC240200582";
    }

    void displayMarks() override
    {
        cout << "\nDerived class Function (Marks)";
    }
};

int main()
{
    cout << "===== Explicit Typecasting Example =====";

    // Explicit Typecasting: base* pointing to derived object
    base* p;             // base class pointer
    derived obj1;        // derived class object
    p = &obj1;           // Explicit: base* = &derived

    p->displayname();    // ✅ allowed: base class function
    p->displayMarks();   // ✅ allowed: overridden in derived, called via virtual

    // p->displayRollNo(); ❌ Not allowed: base class doesn't have displayRollNo()

    // If you really want to call derived-only function:
    // Use explicit cast:
    ((derived*)p)->displayRollNo();  // ✅ allowed through explicit cast

    cout << "\n\n===== Implicit Typecasting Example =====";

    // Implicit Typecasting: derived* pointing to derived object
    derived d;
    derived* p2 = &d;    // Implicit: derived* = &derived

    p2->displayname();   // ✅ allowed: inherited from base
    p2->displayMarks();  // ✅ allowed
    p2->displayRollNo(); // ✅ allowed

    // Implicit Typecasting: base* pointing to base object
    // But base is abstract, so we can't instantiate it
    // base b;              ❌ ERROR: base is abstract, cannot instantiate
    // base* p1 = &b;

    return 0;
}
