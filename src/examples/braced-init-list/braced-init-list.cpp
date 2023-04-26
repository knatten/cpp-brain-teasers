#include <array>
#include <initializer_list>
#include <map>
#include <string>

void f(std::initializer_list<int>);

std::array<int, 2> f()
{
    // START: examples
    std::array<int, 3> a{1, 2, 3};
    int i{2};
    int j{};
    f({1, 2});
    std::map<int, std::string>{{1, "one"}, {2, "two"}};
    return {1, 2};
    // END: examples
}
