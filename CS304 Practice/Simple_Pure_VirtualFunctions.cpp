#include<iostream>
#include<string>
using namespace std;

class shape                     // Abstract class: in which pure virtual function is defined
{
    public:
    virtual void draw()         // simple virtual function: define in base as well as derived class
    {
        cout << "Shape class draw function" << endl;
    }
    virtual void draw() = 0;     // pure virtual function
};
class line: public shape        // Concrete class: inherit from an abstract class
{ 
    virtual void draw()         // here "virtual" keysord is optional
    {
        cout << "Shape class draw function" << endl;
    }

};
int main()
{
    return 0;
}