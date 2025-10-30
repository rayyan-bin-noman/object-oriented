#include <iostream>
using namespace std;

int main()
{
    int i, age [10];
    for (i=0; i<10; i++)
    {
        cout << "Please Enter the Age of student: ";
        cin >> age [i];
    }

    int totalAge=0;
    for (i=0; i<10; i++)
    {
        totalAge += age [i];
    }
    float avrgAge;
    avrgAge = totalAge/10;

    cout << "Average Age of 10 students is " << avrgAge << endl;
    cout << "Thank You";
}