#include<iostream>
#include<string>
using namespace std;

class Test
{
    public:
    int a,b;

    // Parameterized Constructor
    Test (int a, int b)
    {
        this -> a = a;
        this -> b = b;
    }

    // Unary Operator Overloading
    Test operator - ()
    {
        a = -a;
        b = -b;
        return Test(a,b);
    }
    
    void display()
    {
        cout << "\n a: " << a;
        cout << "\n b: " << b;
    }
}; 

int main()
{
    Test T1(-45,89), T2(66,-20);
    -T1;
    T1.display();
    -T2;
    T2.display();
    return 0;
}