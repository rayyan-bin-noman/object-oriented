# include <iostream>
# include <fstream>
using namespace std;

int main()
{
    ifstream myfile;
    myfile.open ("myfile.txt");
    char ch;
    while (!myfile.eof())
    {
        myfile.get(ch);
        cout << ch;
    }

    
}