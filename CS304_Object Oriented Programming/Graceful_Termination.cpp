#include<iostream>
#include<string>
using namespace std;
// Graceful Termination: 
// Program can be designed in such a way that instead of abnormal termination, that 
// causes the wastage of resources, program performs clean up tasks, mean we add 
// check for expected errors (using if conditions)
void Quotient(int &a, int b)
{
    cout << "Please Enter 2 Integers: ";
    cin>>a>>b;
    if (b==0)
    {
        cout << "Denominator can't be Zero" << endl;
        // Do clean up:
        exit(1);
    }
    cout << "\nQuotient of " << a <<" and " << b << " is: " << a/b;
}
int main()
{
    int a,b;
    Quotient(a,b);  // If b = 0, program will be terminated abnormally
    return 0;
}