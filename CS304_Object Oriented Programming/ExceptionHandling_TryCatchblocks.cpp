#include<iostream>
#include<string>
using namespace std;

int main()
{
    try
    {
        int a, b;
        cout << "Please Enter 2 integers: ";
        cin >> a >> b;

        // If denominator is zero, throw a string literal (const char*)
        if (b == 0)
        {
            throw "Denominator is Zero";
        }
        // If denominator is negative, throw an int
        else if (b < 0)
        {
            throw b;  // throws the negative denominator
        }
        else
        {
            // Safe division
            cout << "Quotient of " << a << " and " << b << " is: " << a / b;
        }
    }

    // This catches if b < 0 and was thrown as an int
    catch (int myvalue)
    {
        cout << "Error: Denominator is negative: " << myvalue;
    }

    // This catches all other types of exceptions (like string literal)
    catch (...)
    {
        cout << "Error: Denominator is zero.";
    }

    return 0;
}
