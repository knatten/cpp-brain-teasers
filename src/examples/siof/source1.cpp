#include "Value.h"

#include <iostream>

extern Value value1;
Value value2{value1}; // No guarantee that `value1` has been initialized yet!

int main()
{
    std::cout << value2.i;
}
