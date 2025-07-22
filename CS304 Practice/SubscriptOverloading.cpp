#include<iostream>
#include<string>
using namespace std;

class Test
{
    private:
        int arr[10];
    public:
        Test()
        {
            for (int i=0; i<=9; i++)
            {
                arr[i] = i+1;
            }
        }
        int &operator [](int index)
        {
            if (index < 0 || index > 9)
            {
                cout << "\n Invalid Index";
            }
            else
                return arr[index];
        }
};
int main()
{
    Test T;
    cout << "\n T[0] -> : " << T[0];
    cout << "\n T[5] -> : " << T[5];
    cout << "\n T[9] -> : " << T[9];
    cout << "\n T[13] -> : " << T[13];
    return 0;
}