#include<iostream>
#include<string>
using namespace std;
// template funtion is used for generic data type, template fun. will automatically converts itself according to the passed argumunt's datatype
template <class x, class y>            // x & y....... are generic but will be used as distinct datatypes 
void print(x a, y b)
{
    cout << "Answer is: " << a << "\t\t" << b << "\n\n";
} 
int main()
{
    print(10, 20.45);      // calling for int and float simeltaneously
    print('N', "Rayyan Bin Noman");   // calling for char and string simeltaneously
    print(true,false);   // calling for bool 
    return 0;
}