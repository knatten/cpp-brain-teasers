#include <iostream>

struct GameObject {
    virtual void render() const = 0;
};

template<typename Derived>
struct LoggingGameObject : public GameObject {
    LoggingGameObject() {
        std::cout << "Created a " << Derived::typeName << "\n";
    }
    void render() const override {
        std::cout << "Rendered a " << Derived::typeName << "\n";
    }
};

struct Spaceship : public LoggingGameObject<Spaceship> {
    static constexpr auto typeName = "Spaceship";
};

void display(const GameObject &gameObject) { gameObject.render(); }

int main() {
    Spaceship spaceship;
    display(spaceship);
}
