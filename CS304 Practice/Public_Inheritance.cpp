#include<iostream>
#include<string>
using namespace std;
// In public Inheritance:
//     private data members of base class cannot be accessable in any derived class or main
//     protected data members of base class can be accessable in derived class but cannot be accessable in main
//     public data members of base class can be accessable in derived classes as well as main
class base 
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
class derived: public base
{
    // a = 35;   -> cannot be accessed due to private access specifier
    public:
    void add()
    {
        base::add();
    }
};

int main()
{
    // b = 35;   -> cannot be accessed due to protected access specifier
    derived d;
    d.base::add();
    return 0;
}