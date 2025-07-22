#include<iostream>
#include<string>
using namespace std;

class Test
{
private:
    int age;
    string name;
public:
    Test()
    {
        age = 0;
        name = "";
    }

    // ✅ Fix: Add parameterized constructor
    Test(int a, string n)
    {
        age = a;
        name = n;
    }

    // Overload function call operator
    Test operator ()(int a, string n)
    {
        Test obj;
        obj.age = a;
        obj.name = n;
        return obj;
    }

    void display()
    {
        cout << "\n Name: " << name;
        cout << "\n Age: " << age << endl;
    }
};

int main()
{
    Test T1(45, "Hassan"), T2;

    T1.display();             // Shows Hassan

    T2 = T1(23, "Ali");       // Calls overloaded operator(), returns new object

    T2.display();             // Shows Ali

    return 0;
}
