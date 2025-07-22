#include<iostream>
#include<string>
using namespace std;

class shape                     // Abstract class: in which pure virtual function is defined
{
    public:
    virtual void show()         // simple virtual function: define in base as well as derived class
    {
        cout << "Shape class show function" << endl;
    }
    virtual void draw() = 0;     // pure virtual function: declared anyshere in base or derived class, but it's neccessary to define in derived class
};
class line: public shape        // Concrete class: inherit from an abstract class
{ 
    public:
    virtual void draw()         // Definition of pure Virtual function, here "virtual" keysord is optional
    {
        cout << "Line class draw function" << endl;
    }
    // function overriding:
    void show()                 // while defining simple virtual function in derived class, "virtual" keyword is not used
    {
        cout << "Line class show function" << endl;
    }
};

int main()
{
    shape *s;
    s = new line;
    s -> draw();
    s -> show(); 
    return 0;
}