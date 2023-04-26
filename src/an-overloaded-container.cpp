#include <initializer_list>
#include <iostream>

struct Container
{
    Container(int, int)
    {
        std::cout << "Two ints\n";
    }
    Container(std::initializer_list<float>)
    {
        std::cout << "std::initializer_list<float>\n";
    }
};

int main()
{
    Container container1(1, 2);
    Container container2{1, 2};
}
