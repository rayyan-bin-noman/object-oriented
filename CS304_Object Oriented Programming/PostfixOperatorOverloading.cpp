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
        this ->a = a;
    }

    // Postfix Increment
    Test& operator ++(int)
    {
        a++;
        return *this;
    }

    // Postfix Decrement
    Test& operator --(int)
    {
        a--;
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
    Test T2 = T1++;  // Assign to T2, Increment T1
    T2.display();    // Shows updated value
    T1 = T2--;       // Assign to T1, Decrement T2
    T1.display();    // Shows updated value
    return 0;
}
