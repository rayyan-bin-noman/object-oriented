#include <iostream>
using namespace std;

int main()
{
    cout <<"My name is Rayyan & now I am telling you the 4 digits seperately that you will enter in input." << endl;
    int userinput;
    int firstdigit, seconddigit, thirddigit, fourthdigit;
    cout << "Please enter any 4 digit integer: ";
    cin >> userinput;
    if (userinput> 9999 || userinput<1000)
    {
        cout << "Your input is invalid";
        return 0;
    }
    else
    { 
        fourthdigit = userinput % 10;
        userinput = userinput / 10;
        thirddigit = userinput % 10;
        userinput = userinput / 10;
        seconddigit = userinput % 10;
        userinput = userinput / 10;
        firstdigit = userinput % 10;
    }
    cout << "Your First Digit is : " << firstdigit << endl;
    cout << "Your second Digit is : " << seconddigit << endl;
    cout << "Your Third Digit is : " << thirddigit << endl;
    cout << "Your Fourth Digit is : " << fourthdigit << endl;

    cout << "Thank You!";
   
   return 0;
}