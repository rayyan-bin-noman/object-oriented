#include<iostream>
#include<string>
using namespace std;

class grandparent
{
    int gp;
    public:
    grandparent(): gp(35)
    {
        cout << "\nGrandparent gp: " << gp;
    }
};
class parent: public grandparent
{
    int p;
    public:
    parent(): grandparent(), p(25)
    {
        cout << "\nParent p: " << p;
    }
};
class child: public parent
{
    int c;
    public:
    // child(): grandparent(), c(15)    ->   WRONG
    child(): parent(), c(15)
    {
        cout << "\nChild c: " << c;
    }
};

int main()
{
    child c;
    return 0;
}