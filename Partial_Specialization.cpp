#include<iostream>
#include<string>
using namespace std;
// Partial Specialization: mixing primitive and generic datatypes at a time
template<class T1, int T2>    // T1 = Generic Data type, T2 = Primitive data type (int or could be anything)
class myclass
{
    T1 a;
    int b;
    public:
    myclass(T1 num1, int num2)    // num1 contains value of any datatype, num2 contains only int value 
    {
        a = num1;
        b = num2;
    }
    void show()
    {
        cout << "\n" << a << b << endl;
    }
};
int main()
{
    myclass<string,45> obj("My age is: ",20);         // in <>, tell datatype for generic value and tell explicit value for primitive datatype
    obj.show();
    return 0;
}