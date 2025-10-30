#include <iostream>
using namespace std;
double circle_area (double);
int main()
{
    double rad1,rad2,ring_area;
    cout << "Please Enter the radius of outer circle: ";
    cin >> rad1;
    cout << "Please Enter the radius of inner circle: ";
    cin >> rad2;
    ring_area = circle_area (rad1) - circle_area (rad2);
    cout << "The Area of Ring having outer radius " << rad1 << " and inner radius " << rad2 << " is " << ring_area;
}

double circle_area (double radius)
{
    return (3.1415926 * radius * radius);
}