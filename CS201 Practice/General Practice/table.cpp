#include <iostream>
using namespace std;

int main()
{
    cout <<"My name is Rayyan & I will make for you multiplicative table of any integer from 1 upto the inputted range." << endl;
    int multiplier, multiplicand, range;
    cout << "Please enter the multiplier (the number with which we multiply) = " ;
    cin >> multiplier;
    cout << "Please tell the range of multiplicand (the number to be multiplied) = " ;
    cin >> range;
    for (multiplicand=1; multiplicand<=range; multiplicand++)
    {
        cout << multiplier << " X " << multiplicand << " = " << multiplier*multiplicand << endl;
    }
    
    cout << "Thank You!";

}
   


