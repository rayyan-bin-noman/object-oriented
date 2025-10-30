#include <iostream>
using namespace std;

int main()
{
    int i, j;

    i = 4;
    j = 2 * i++;    // j= 2 * 4 = 8, then i becomes 5 (from 4)
    i = 2 * --j;    // First j becomes 7 (from 8) then i= 2 * 7 = 14
                    // Finally i becomes 14 & j becomes 7
    cout << "Value of i is: " << i << " & Value of j is: " << j;
}