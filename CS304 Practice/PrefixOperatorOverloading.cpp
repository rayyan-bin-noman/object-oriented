#include<iostream>
#include<string>
using namespace std;

class Test
{
public:
    int a;

    // Default Constructor
    Test()
    {
        a = 0;
    }

    // Parameterized Constructor
    Test(int a)
    {
        this->a = a;
    }

    // Prefix Increment
    Test& operator++()
    {
        ++a;
        return *this;
    }

    // Prefix Decrement
    Test& operator--()
    {
        --a;
        return *this;
    }

    void display()
    {
        cout << "a: " << a << endl;
    }
};

int main()
{
    Test T1(30); 
    Test T2 = ++T1;  // Increment T1, assign to T2
    T2.display();    // Shows updated value
    T1 = --T2;       // Decrement T2, assign to T1
    T1.display();    // Shows updated value
    return 0;
}
