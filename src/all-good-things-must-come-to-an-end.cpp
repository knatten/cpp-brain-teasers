#include <iostream>
#include <string>

struct Connection
{
    Connection(const std::string &name) : name_(name)
    {
        std::cout << "Created " << name_ << "\n";
    }

    ~Connection() {
        std::cout << "Destroyed " << name_ << "\n";
    }

    std::string name_;
};

Connection global{"global"};

Connection &get()
{
    static Connection localStatic{"local static"};
    return localStatic;
}

int main()
{
    Connection local{"local"};
    Connection &tmp1 = get();
    Connection &tmp2 = get();
}