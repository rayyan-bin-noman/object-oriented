#include<iostream>
#include<string>
using namespace std;
template<class T>
class temp          // template class
{
    public:
    T a,b;
    temp(T,T);      // only declaration of template class constructor (optional)
    T sum();        // only declaration of sum() function
};
template<class T>    // this line is neccessary when we define anything of template class oustside of it
temp<T>::temp(T x, T y)
{
    a = x;
    b = y;
}
template<class T>    // this line is neccessary when we define anything of template class oustside of it
T temp<T>::sum()
{
    cout << "SUM is: \t" << a+b;
}
int main()
{
    temp<int> obj1(100,250);
    temp<float> obj2(100.35,250.67);
    obj1.sum();
    obj2.sum();
    return 0;
}