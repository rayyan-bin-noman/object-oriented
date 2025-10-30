#include<iostream>
#include<string>
using namespace std;

class base
{
    int a;
    public:
    base(int x): a(x)
    {
        cout << "\n a: " << a;
    }
};

class derived : public base
{
    int b;
    public:
    derived(int x, int y): base(x), b(y)
    {
        cout << "\n b: " << b;
    }
};

int main()
{
    derived d(45,77);
    return 0;
}