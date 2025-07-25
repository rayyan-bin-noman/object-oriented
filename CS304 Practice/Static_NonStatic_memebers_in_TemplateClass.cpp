#include<iostream>
#include<string>
using namespace std;
// KEY DIFFERENCES:
// | Feature        | **Static Member**                          | **Non-Static Member**                 |
// | -------------- | ------------------------------------------ | ------------------------------------- |
// | Memory         | One copy per template instantiation        | Separate copy per object              |
// | Accessed by    | `ClassName::member` or `object.member`     | Only by `object.member`               |
// | Lifetime       | Exists even without any object             | Exists only with object               |
// | Initialization | Must be defined **outside** class          | Can be initialized in constructor     |
// | Usage          | Useful for counting objects, sharing state | Used for storing object-specific data |

template<typename T>
class MyClass
{
public:
    T data;               // Non-static
    static int count;     // Static

    MyClass(T val) {
        data = val;
        count++;
    }

    void show() {
        cout << "Data: " << data << ", Count: " << count << endl;
    }
};

// Static member definition (always outside the class)
template<typename T>
int MyClass<T>::count = 0;

int main()
{
    MyClass<int> obj1(10);   // count = 1 for MyClass<int>
    MyClass<int> obj2(20);   // count = 2 for MyClass<int>
    MyClass<double> obj3(3.14); // count = 1 for MyClass<double>

    obj1.show();  // Output: Data: 10, Count: 2
    obj2.show();  // Output: Data: 20, Count: 2
    obj3.show();  // Output: Data: 3.14, Count: 1

    return 0;
}
