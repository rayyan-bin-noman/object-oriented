#include<iostream>
#include<string>
using namespace std;
// Overloding: Within the same class
// Overriding: Within Base & Derived class
class base
{
    public:
    // function Overloading
    void sum(int a, int b)
    {
        cout << "\n Sum of Base class function with two arguments is: " << a+b;
    }
    void sum(int a, int b, int c)
    {
        cout << "\n Sum of Base class function with three arguments is: " << a+b+c;
    }
};
class derived : public base
{
    // function overriding
    public:
    void sum(int a, int b, int c)
    {
        base::sum(a,b,c);
    }
    // function overloading
    void sum(int a, int b)
    {
        base::sum(a,b);
    }

};
int main()
{
    base b;
    b.sum(7,89,100);
    b.sum(7,89);
    derived d;
    d.sum(12,23,45);
    d.sum(12,23);
    return 0;
}