#include <iostream>
#include <string>

void serialize(const void*) { std::cout << "const void*"; }

void serialize(const std::string&) { std::cout << "const string&"; }

int main()
{
    serialize("hello world");
}
