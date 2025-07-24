#include<iostream>
#include<string>
using namespace std;

template<typename T1, typename T2>
class MyClass
{
public:
    void show()
    {
        cout << "\nGeneric template\n";
    }
};
//Partial Specialization: When both types are the same
template<typename T>
class MyClass<T, T>
{
public:
    void show()
    {
        cout << "Partial specialization: both types same\n";
    }
};
//Full Specialization: Only when T1 = int, T2 = float
template<>
class MyClass<int, float>
{
public:
    void show()
    {
        cout << "Full specialization: int, float\n";
    }
};
int main()
{
    MyClass<char, double> a;     // Generic template
    MyClass<int, float> b;       // Full specialization
    MyClass<string, string> c;   // Partial specialization

    a.show();   // Output: Generic template
    b.show();   // Output: Full specialization: int, float
    c.show();   // Output: Partial specialization: both types same
}
