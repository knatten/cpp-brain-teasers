#include <iostream>

// START: base
struct Monster
{
    Monster() = default;
    Monster(const Monster &other) {
        std::cout << "Monster copied\n";
    }
};
// END: base

struct Jormungandr : public Monster
{
    Jormungandr()= default;
    Jormungandr(const Jormungandr &other) : Monster(other)
    {
        std::cout << "Jormungandr copied\n";
    }
    // START: std-move
    Jormungandr(Jormungandr &&other) : Monster(std::move(other))
    // END: std-move
    {
        std::cout << "Jormungandr moved\n";
    }
};

int main()
{
    Jormungandr jormungandr1;
    Jormungandr jormungandr2{std::move(jormungandr1)};
}
