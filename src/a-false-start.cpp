#include <iostream>
#include <stdexcept>

struct Engine
{
    ~Engine() { std::cout << "Engine stopped\n"; }
};

struct Machine
{
    Machine() { throw std::runtime_error{"Failed to start machine"}; }
    ~Machine() { std::cout << "Machine stopped\n"; }

    Engine engine_;
};

int main()
{
    try
    {
        Machine machine;
    }
    catch (...)
    {
    }
}
