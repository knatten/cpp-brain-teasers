#include <iostream>

struct Resource
{
    Resource() = default;
    Resource(const Resource &other) { std::cout << "copy\n"; }
};

namespace URVO
{
    // START: URVO
    Resource getResource() {
        return Resource{}; // Unnamed RVO (pre C++17)
    }
    // END: URVO
} // namespace URVO

namespace NRVO
{
    // START: NRVO
    Resource getResource()
    {
        Resource resource;
        return resource; // Named RVO
    }
    // END: NRVO
} // namespace NRVO

int main()
{
    Resource resource1 = URVO::getResource();
    Resource resource2 = NRVO::getResource();
}
