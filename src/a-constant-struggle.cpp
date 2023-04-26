#include <iostream>
#include <type_traits>

template <typename T>
void byValue(T t)
{
    std::cout << std::is_const_v<T>; // true if T is const
}

template <typename T>
void byReference(T &t)
{
    std::cout << std::is_const_v<T>; // true if T is const
}

int main()
{
    int nonConstInt = 0;
    const int constInt = 0;

    byValue(nonConstInt);
    byValue(constInt);

    byReference(nonConstInt);
    byReference(constInt);
}