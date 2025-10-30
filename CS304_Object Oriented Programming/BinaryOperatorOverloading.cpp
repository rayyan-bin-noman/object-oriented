#include<iostream>
#include<string>
using namespace std;

class Test
{
    public:
    string name;
    Test (string name)
    {
        this -> name = name;
    }
    Test& operator=(const Test& obj)
    {
        this -> name = obj.name;
        return *this;
    }

    string operator = (string n)
    {
        name = n;
        return name;
    }
};

int main()
{
    Test T1("Hafiz Sahab"), T2("Ali");
    Test T3 = T2 = T1;
    string name = T1 = "Rayyan Bin Noman";
    cout << "\n T1 name: " << T1.name;
    cout << "\n T2 name: " << T2.name;
    cout << "\n T3 name: " << T3.name;
    cout << "\n Name: " << name;

    return 0;
}