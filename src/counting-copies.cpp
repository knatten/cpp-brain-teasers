#include <iostream>

struct Resource
{
    Resource() = default;
    Resource(const Resource &other)
    {
        std::cout << "copy\n";
    }
};

Resource getResource()
{
    return Resource{};
}

int main()
{
    Resource resource1 = getResource();
    Resource resource2{resource1};
}