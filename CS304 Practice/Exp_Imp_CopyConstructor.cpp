#include<iostream>
#include<string>
using namespace std;

class base
{
    int a;
    public:
    base(int n)         // Implicit Copy Constructor
    {
        a = n;
    }
    base(base &obj)     // Explicit Copy Constructor
    {
        a = obj.a;
        cout << "\n a: " << a;
    } 
};
int main()
{
    base b1(25);
    base b2(b1);
    return 0;
}