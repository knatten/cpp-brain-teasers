#include <iostream>

struct Resource
{
    Resource()
    {
        std::cout << "Resource constructed\n";
    }
};

struct Consumer
{
    Consumer(const Resource &resource)
    {
        std::cout << "Consumer constructed\n";
    }
};

struct Job
{
    Job() : resource_{}, consumer_{resource_} {}
    Consumer consumer_;
    Resource resource_;
};

int main() {
    Job job;
}
