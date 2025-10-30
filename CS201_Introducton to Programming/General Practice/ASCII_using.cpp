#include <iostream>
using namespace std;

int main ()
{
    char character;
    character = 'A' + 32;              // ASCII value of a=97, A=65 & space=32
    cout << character << endl;

    character = 'A' + ' ' ;
    cout << character << endl;

    character = 65 + ' ';
    cout << character << endl;

    character = 97 - ' ';
    cout << character << endl;

    character = 'a' - 32;
    cout << character << endl;

    character = 'a' - ' ';
    cout << character;
}