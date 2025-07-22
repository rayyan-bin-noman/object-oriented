# include <iostream>
using namespace std;

int main()
{
    int x=10;
    int *yptr;
    yptr = &x;
    cout << yptr << "\n";   // hexadecimal representation of memory address where the value of x=10 stored
    cout << *yptr << "\n";  // Value stored in yptr that is &x or 10
    *yptr ++; 
    yptr++;              // Increment whatever yptr points to (Now x=11)
    cout << yptr << "\n";   // hexadecimal representation of memory address where the value of x=10 stored
    cout << *yptr << "\n";  // Value stored in yptr that is &x or 10

}