// This Program Compare two Arrays and Display Result whether both are equal or not
#include <iostream>
using namespace std;

int main ()
{
    int num1[5], num2[5], i, equals;
    cout << "Please Enter 5 +ve integers for Array 1: " << endl;
    // taking input for first Array
    for (i=0; i<5; i++)
    cin >> num1[i];

    cout << "Please Enter 5 +ve integers for Array 2: " << endl;  
    // taking input for second Array
    for (i=0; i<5; i++)
    cin >> num2[i];

    // Display the Result of First Array
    cout << "The values in the First Array are: ";
    for (i=0; i<5; i++)
    cout << "\t" << num1[i];

    // Display the Result of Second Array
    cout << "\nThe values in the Second Array are: ";
    for (i=0; i<5; i++)
    cout << "\t" << num2[i];

    // Comparision of both Arrays whether they are Equal or not
    for (i=0; i<5; i++)
    {
        if (num1[i] != num2[i])
        {
            cout << "\nBoth Arrays are not Equal";
            equals = 0; // Set the Flag to False
    break;
        }
            equals = 1; // Set the Flag to True
    }
    if (equals == 1)
    cout << "\nBoth Arrays are Equal";

cout << "\nThank You!";

}
