#include<iostream>
#include<string>
using namespace std;
// (a) Return Illegal value:
// The clean-up tasks are of local nature only; there remains the possibility of information loss.

// (b) Return error code:
// Programmer has avoided the system crash but the program is now in an inconsistent state 
class myclass
{
    public:
    void Quotient1(int a, int b)
    {
        cout << "Please Enter 2 Integers: ";
        cin>>a>>b;
        if (b==0)
        {
            b = 1;      //You changed the error cause by yourself
            cout << "**--Returning Illegal Value--**"; 
        }
        else
        {
            cout << "\nQuotient of " << a <<" and " << b << " is: " << a/b;
        }
    }

    bool Quotient2(int a, int b)
    {
        cout << "Please Enter 2 Integers: ";
        cin>>a>>b;
        if (b==0)
        {
            return true;
        }
        else
        {
            return false; 
        }   
    }
 
};
int main()
{
    int a,b;
    myclass obj1;
    obj1.Quotient1(a,b);

    void CheckQuotient2
    {
        if (Quotient2(a,b))
        {
            cout << "Denominator can't be zero";
            exit(0);
        }
        else
        cout << "\nQuotient of " << a <<" and " << b << " is: " << a/b;
    } 
    return 0;
}