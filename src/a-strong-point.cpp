#include <iostream>

struct Points
{
    Points(int value) : value_(value) {}
    int value_;
};

struct Player
{
    explicit Player(Points points) : points_(points) {}
    Points points_;
};

int main()
{
    Player player(3);
    std::cout << player.points_.value_;
}