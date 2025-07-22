#include<iostream>
#include<string>
using namespace std;
class Engine
{
    public: 
    Engine()
    {
        cout << "\n Engine Constructor";
    }
    void start()
    {
        cout << "\n Engine start";
    }
    ~Engine()
    {
        cout << "\n Engine Destructor";
    }
};

class Wheels
{
    public: 
    Wheels()
    {
        cout << "\n Wheels Constructor";
    }
    void move()
    {
        cout << "\n Wheels Move";
    }
    ~Wheels()
    {
        cout << "\n Wheels Destructor";
    }
};

class Car
{
    public:
    Engine E;
    Wheels W; 
    Car()
    {
        cout << "\n Car Constructor";
    }
    ~Car()
    {
        cout << "\n Car Destructor";
    }
};

int main()
{
    Car C;
    C.E.start();
    C.W.move();
    return 0;
}