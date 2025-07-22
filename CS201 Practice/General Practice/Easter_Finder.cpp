#include <iostream>
using namespace std;

int main ()
{
    int year;
    int a, b, c, d, e;
    cout << "Please Enter any Year of 20th or 21st Century: ";
    cin >> year;
    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = ((a * 19) + 24) % 30;
    e = (2*b + 4*c + 6*d + 5) % 7;

    if ((d + e) < 10)
        cout << "Easter falls on March " << (d + e + 22);
    else
        cout << "Easter falls on April " << (d + e - 9);

    cout << "\n" "Thank You!";
}