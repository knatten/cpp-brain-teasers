#include <iostream>

struct Member
{
};

struct WillItMove
{
    WillItMove() = default;
    WillItMove(WillItMove &&) = default;
    const Member constMember_{};
};

int main()
{
    WillItMove objectWithConstMember;
    WillItMove moved{std::move(objectWithConstMember)};
    std::cout << "It moved!\n";
}