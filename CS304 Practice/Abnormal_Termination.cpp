#include<iostream>
#include<string>
using namespace std;
// Abnormal Termination: 
// In abnormal termination we do nothing and our program is terminated abnormally 
// by operating system if case of any error without saving program data
void Quotient(int &a, int b)
{
    cout << "Please Enter 2 Integers: ";
    cin>>a>>b;
    cout << "\nQuotient of " << a <<" and " << b << " is: " << a/b;
}
int main()
{
    int a,b;
    Quotient(a,b);  // If b = 0, program will be terminated abnormally
    return 0;
}