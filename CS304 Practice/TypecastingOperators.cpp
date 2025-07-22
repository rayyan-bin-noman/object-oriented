#include<iostream>
#include<string>
using namespace std;

// (1) static_cast -> used to Downcasting (casting from base to derived class)
// (2) const_cast -> used to Upcasting (casting from derived to base class)
// (3) reinterpret_cast -> used to Downcasting (casting from base to derived class)
// (4) dynamic_cast -> used to Array Casting

class base
{
    public:
    void myfun()
    {
        cout << "\n Base Class Function";
    }
};

class derived: public base
{
    public:
    void myfun()
    {
        cout << "\n Derived Class Function";
    }
};

int main()
{
    // // using static_cast (Downcasting) -> same code for reinterpret_cast operator (Downcasting)
    // base *b = new derived;
    // b -> myfun();
    // derived *d = static_cast <derived*> (b);       // <in which converted> (who is conveerted)
    // d -> myfun();

    // using dynamic_cast (Upcasting)
    derived *d = new derived;
    d -> myfun();
    base *b = dynamic_cast <base*> (d);       // <in which converted> (who is conveerted)
    b -> myfun();
    return 0;
}