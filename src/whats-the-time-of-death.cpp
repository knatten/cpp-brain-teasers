#include <iostream>

struct MemoryArea
{
    MemoryArea(int number) : number_(number) {}
    ~MemoryArea() { std::cout << "Freed memory area " << number_ << "\n"; }

    int number_;
};

MemoryArea getMemory(int number) { return MemoryArea{number}; }

struct DataSource
{
    DataSource(const MemoryArea &memoryArea)
        : memoryArea_(memoryArea) {}
    const MemoryArea &memoryArea_;
};

int main()
{
    const auto &reference1 = getMemory(1);
    std::cout << "Bound reference 1\n";
    const auto &reference2 = getMemory(2).number_;
    std::cout << "Bound reference 2\n";
    const auto &reference3 = DataSource(getMemory(3));
    std::cout << "Bound reference 3\n";
}