#include<iostream>
#include<string>
using namespace std;

class grandparent
{
    public:
    void print()
    {
        cout << "\nGrandparent class";
    }
};
class parent: public grandparent
{
    public:
    void print()
    {
        cout << "\nParent class";
    }
};
class child: public parent
{
    public:
    void print()
    {
        cout << "\nChild class";
    }
};

int main()
{
    child c;
    c.print();
    c.grandparent::print();
    c.parent::print();
    return 0;
}