#include <future>
#include <iostream>

int main()
{
    char counter = 0;

    auto future1 = std::async(std::launch::async, [&]()
    {
      counter++;
    });
    auto future2 = std::async(std::launch::async, [&]()
    {
      return counter;
    });

    future1.wait();

    // Cast to int to print it as a numerical value rather than a character
    std::cout << (int)future2.get();
}
