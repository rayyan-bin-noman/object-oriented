#include<iostream>
#include<string>
using namespace std;

class base
{
    protected:
    void displayname()
    {
        cout << "\n My Name is Rayyan Bin Noman";
    }
};

class derived : public base
{
    public:
    void callingFun()
    {
        displayname();
    }
};

int main()
{
    derived d;
    d.callingFun();
    return 0;
}