#include <iostream>
using namespace std;
double raiseToPow (double,int);
int main()
{
    double x;
    int i;
    cout << "Please Enter the number: ";
    cin >> x;
    cout << "Pleaser Enter the Integer Power that you want this number raised to: ";
    cin >> i;
    cout << x << " raised to the power " << i << " is " << raiseToPow (x,i);
}

double raiseToPow (double x, int power)
{
    double result;
    int i;
    result = 1.0;

    for (i=1; i<=power; i++)
    {
        result *= x;
    }
    return (result);
}