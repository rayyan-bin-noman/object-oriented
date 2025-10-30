#include<iostream>
#include<string>
using namespace std;

class shape
{
    public:
    virtual void draw()              // virtual function is used for runtime polymorphism which depends on actual object
    {
        cout << "draw function for shape" << endl;
    }
};
class line: public shape
{
    public:
    void draw()
    {
        cout << "draw function for line" << endl;
    }
};
class square: public shape
{
    public:
    void draw()
    {
        cout << "draw function for square" << endl;
    }
};
class circle: public shape
{
    public:
    void draw()
    {
        cout << "draw function for circle" << endl;
    }
};
class triangle: public shape
{
    public:
    void draw()
    {
        cout << "draw function for triangle" << endl;
    }
};
int main()
{
    shape *shp;
    shp = new line;
    shp -> draw();           // without virtual function, it always run base class's draw() function
    shp = new square;
    shp -> draw();
    shp = new circle;
    shp -> draw();
    shp = new triangle;
    shp -> draw();

    return 0;
}