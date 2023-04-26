#include <iostream>
#include <string>

std::string getName()
{
    return "Alice";
}

int main()
{
    std::string name{"Bob"};
    getName() = name;
    std::cout << "Assigned to a function!\n";
}
