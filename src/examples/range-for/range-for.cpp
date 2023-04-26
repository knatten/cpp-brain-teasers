#include <iostream>
#include <vector>

struct MemoryArea
{
    MemoryArea(int number) : number_(number) {}
    ~MemoryArea() { std::cout << "Freed memory area " << number_ << std::endl; }

    int number_;
};

// START: class
class MemoryAreaContainer
{
  public:
    MemoryAreaContainer();
    std::vector<MemoryArea> &getMemoryAreas()
    {
        return memoryAreas_;
    }

  private:
    std::vector<MemoryArea> memoryAreas_;
};
// END: class

MemoryAreaContainer::MemoryAreaContainer()
    : memoryAreas_{MemoryArea{1}, MemoryArea{2}}
{
}

int main()
{
    // START: loop
    for (const auto &lp : MemoryAreaContainer{}.getMemoryAreas())
    {
        std::cout << lp.number_ << std::endl;
    }
    // END: loop
}
