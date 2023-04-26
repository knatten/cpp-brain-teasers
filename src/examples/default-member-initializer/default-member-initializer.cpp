#include <iostream>

struct Degrees
{
    Degrees() : degrees_(0)
    {
        std::cout << "Default constructed\n";
    }
    Degrees(double degrees) : degrees_(degrees)
    {
        std::cout << "Constructed with " << degrees_ << "\n";
    }
    double degrees_;
};

// START: default-member-initializer
struct Position
{
    Position() { longitude = Degrees{2}; }
    Degrees latitude{1}; // Default member initializer
    Degrees longitude;
};
// END: default-member-initializer

int main()
{
    Position position;
}
