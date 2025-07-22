#include<iostream>
#include<string>
using namespace std;

class person
{
    int id;
    string name;
    public:
    person(int i, string n)     //Abstract Class
    {
        id = i;
        name = n;
    }
    // Simple Virtual functions:
    virtual int getID()
    {
        return id;
    }
    virtual string getname()
    {
        return name;
    }
    // Pure VIrtual Function:
    virtual void display() = 0;
};
class student: public person            //Concrete Class: Inherit with Abstract class
{
    float marks;
    public:
    student(int i, string n, float m): person(i,n)      //using memmbers initializer list to call base class's constructor (for ID and Name)
    {
        marks = m;
    }
    void display()                                  // Definition of pure virtual function
    {
        cout << "*** Student's Record ***";
        cout << "\n\n Student's ID: " << getID();
        cout << "\n Student's name: " << getname();
        cout << "\n Student's marks: " << marks;
    }
};
class teacher: public person            //Concrete Class: Inherit with Abstract class
{
    string qualification;
    public:
   teacher(int i, string n, string q): person(i,n)      //using memmbers initializer list to call base class's constructor (for ID and Name)
    {
        qualification = q;
    }
    void display()                                  // Definition of pure virtual function
    {
        cout << "\n\n*** Teacher's Record ***";
        cout << "\n\n Teacher's ID: " << getID();
        cout << "\n Teacher's name: " << getname();
        cout << "\n Teacher's Qualification: " << qualification;
    }
};

int main()
{
    person *p[2];       // base class's array of pointers: p[0],p[1]
    p[0] = new student(45, "Rayyan Bin Noman", 97.58);
    p[0] -> display();
    p[1] = new teacher(20, "Dr. Anwar Ali", "PHD in Molecular Medicine");
    p[1] -> display();
    return 0;
}