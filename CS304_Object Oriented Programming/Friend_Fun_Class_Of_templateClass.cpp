#include<iostream>
#include<string>
class ord;              // declare class Y with the header file when class Y is used in above class A, bec. compiler will not know class ord when compiling it in class temp
void sum();             // same case for sum function as above
using namespace std;

template<class T1>
class temp
{
    T1 name, ID, a, b;
    friend class ord;         // making ordinary class as a friend of template class 
    friend void sum();         // making sum function as a friend of template class 
};
class ord
{
    public:
    // making object of template/friend class:
    temp<string> n;
    temp<string> id;
    // Constructor
    ord()
    {
        n.name = "Rayyan Bin Noman";
        id.ID = "BC240200582";
    }
    void display()
    {
        cout << "\nMy Name is: " << n.name;      //class ord is friend of class temp so it can access temp's private members
        cout << "\nMy ID is: " << id.ID << endl;          // same here
    }
};
void sum()
{
    // making object of temp class
    temp<int> num1;
    num1.a = 23;        //sum() function is friend of class temp so it can access temp's private members
    num1.b = 34;        // same here
    cout << "\nSum of " << num1.a << " and " << num1.b << " is: " << num1.a + num1.b << endl;
}
int main()
{
    ord obj1;
    obj1.display();
    sum();
    return 0;
}