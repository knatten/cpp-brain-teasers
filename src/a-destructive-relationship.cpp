#include <iostream>
#include <memory>

struct Widget
{
    virtual void draw() { std::cout << "Widget draw\n"; }
    virtual ~Widget() { std::cout << "Widget destructor\n"; }
};

struct Button : public Widget
{
    void draw() override { std::cout << "Button draw\n"; }
    ~Button() override { std::cout << "Button destructor\n"; }
};

int main()
{
    std::unique_ptr<Widget> widget = std::make_unique<Button>();
    widget->draw();
}