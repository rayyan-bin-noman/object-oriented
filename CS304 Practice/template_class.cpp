#include<iostream>
#include<string>
using namespace std;

template<class T>
class temp
{
    public:
        T a, b;
        temp(T, T);
        T sum();
};

template<class T>
temp<T>::temp(T x, T y)
{
    a = x;
    b = y;
}

template<class T>
T temp<T>::sum()
{
    return a + b;
}

int main()
{
    temp<int> obj1(100, 250);
    temp<float> obj2(100.35, 250.67);

    cout << "SUM is: \t" << obj1.sum() << endl;
    cout << "SUM is: \t" << obj2.sum() << endl;

    return 0;
}
