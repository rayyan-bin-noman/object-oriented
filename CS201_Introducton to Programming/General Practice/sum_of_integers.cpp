#include <iostream>
using namespace std;

int main()
{
    cout <<"My name is Rayyan & I will tell you the sum of even & odd integeers from 1 upto the inputted range." << endl;
    int evensum=0, oddsum=0,number=1, input=0;
    cout << "Please tell valid range of integers = ";
    cin >> input;
    while (number<=input)
    { 
        if (number%2==0)
        {
            evensum=evensum+number;
        }
        else 
        {
            oddsum=oddsum+number;
        }
            
            number++;

    }
    cout << "The sum of all even integers from 1 to " << input << " is " << evensum << endl;
    cout << "The sum of all odd integers from 1 to " << input << " is " << oddsum << endl;
    
    cout << "Thank You!";

}
   


