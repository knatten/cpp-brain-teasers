#include <iostream>

struct Logger {};
struct Configuration {};

Logger initializeLogger()
{
    std::cout << "Initializing logger\n";
    return Logger{};
}

Configuration readConfiguration()
{
    std::cout << "Reading configuration\n";
    return Configuration{};
}

void startProgram(Logger logger, Configuration configuration)
{
    std::cout << "Starting program\n";
}

// START: main
int main()
{
    const auto logger = initializeLogger();
    const auto configuration = readConfiguration();
    startProgram(logger, configuration);
}
// END: main
