#include <iostream>
using namespace std;

int main(void)
{
    double *iptr, *sptr;
    while (iptr != NULL)
    {
        iptr = (double *)malloc (1000 * (sizeof(double)));
        cout << sizeof(iptr);
        iptr = sizeof(iptr) * sizeof(iptr);
    }
}