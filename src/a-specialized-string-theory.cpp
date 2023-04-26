#include <iostream>

template<typename T>
void serialize(T&) { std::cout << "template\n"; } // 1

template<>
void serialize<>(const std::string&) { std::cout << "specialization\n"; } // 2

void serialize(const std::string&) { std::cout << "normal function\n"; } // 3

int main()
{
    std::string hello_world{"Hello, world!"};
    serialize(hello_world);
    serialize(std::string{"Good bye, world!"});
}
