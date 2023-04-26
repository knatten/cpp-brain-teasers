#include <iostream>

class GameObject {
    // START: GameObject-default
  public:
    GameObject() : GameObject("GameObject"){}
    // END: GameObject-default
    // START: GameObject-param
  protected:
    GameObject(std::string_view type) {
        std::cout << "Created a " << type << "\n";
    }
    // END: GameObject-param
  public:
    void render() const { std::cout << "Rendered a " << getType() << "\n"; }

  protected:
    virtual std::string getType() const { return "GameObject"; }
};

class Spaceship : public GameObject {
    // START: Spaceship-param
  public:
    Spaceship() : GameObject("Spaceship"){}
    // END: Spaceship-param
  private:
    std::string getType() const override { return typeName; }
    static constexpr auto typeName = "Spaceship";
};

void display(const GameObject &gameObject) { gameObject.render(); }

int main() {
    GameObject gameObject;
    Spaceship spaceship;
    display(gameObject);
    display(spaceship);
}
