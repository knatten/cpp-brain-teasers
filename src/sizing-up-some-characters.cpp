#include <iostream>

void serialize(char characters[])
{
    std::cout << sizeof(characters) << "\n";
}

int main()
{
    char characters[] = {'a', 'b', 'c'};
    std::cout << sizeof(characters) << "\n";
    std::cout << sizeof(characters) / sizeof(characters[0]) << "\n";
    serialize(characters);
}