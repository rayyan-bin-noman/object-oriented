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
    Test operator + (Test obj)
    {
        obj.a += a;
        obj.b += b;
        return obj;
    }

}; 

int main()
{
    Test obj1 (100,50), obj2 (20,30), obj3 (65,75);
    Test T = obj1 + obj2 + obj3;
    cout << "\n Sum: " << T.a + T.b;
    return 0;
}