#include <iostream>

struct Monster
{
    Monster() = default;
    Monster(const Monster &other)
    {
        std::cout << "Monster copied\n";
    }
    Monster(Monster &&other)
    {
        std::cout << "Monster moved\n";
    }
};

struct Jormungandr : public Monster
{
    Jormungandr() = default;
    Jormungandr(const Jormungandr &other) : Monster(other)
    {
        std::cout << "Jormungandr copied\n";
    }
    Jormungandr(Jormungandr &&other) : Monster(other)
    {
        std::cout << "Jormungandr moved\n";
    }
};

int main()
{
    Jormungandr jormungandr1;
    Jormungandr jormungandr2{std::move(jormungandr1)};
}