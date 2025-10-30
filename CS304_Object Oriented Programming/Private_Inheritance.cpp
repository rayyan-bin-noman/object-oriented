#include<iostream>
#include<string>
using namespace std;
// In private Inheritance:
//     private data members of grandparent class cannot be accessable in any parent class or main
//     protected data members of grandparent class can be accessable in 1st parent class but cannot be accessable in child classes & in main
//     public data members of grandparent class can be accessable in 1st parent class but cannot be accessable in child classes & in main
class grandparent 
{
    private:
    int a = 10;
    protected:
    int b = 20;
    public:
    void add()
    {
        cout << a << " + " << b << " = " << a+b;
    }
};
class parent: private grandparent
{
    // a = 35;   -> cannot be accessed due to private access specifier
    public:
    parent()
    {
        cout << "b: " << b << "\n";         // b (protected member of grandparent class) -> can be access in 1st child class
        grandparent::add();                // grandparent::add() -> can be access in 1st child class
    }
    
};
class child: public parent
{
    // public:
    // child()
    // {
    //     cout << "b: " << b;         b (protected member of grandparent class) -> can't be access in child class
    // }
    // void add()
    // {
    //     grandparent::add();                grandparent::add() -> can't be access in child class
    // }
};
int main()
{
    // b = 35;   -> cannot be accessed due to protected access specifier
    parent d;
    // d.grandparent::add();     -> can't be access public data members of grandparent class outside it's child class in private inheritance
    // d.add();      -> also this
    return 0;
}