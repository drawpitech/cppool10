#include <iostream>

#include "../AFruit.hpp"
#include "../FruitBox.hpp"

class TestFruit : public AFruit {
   public:
    TestFruit(std::string name) : AFruit(0, std::move(name), false) {
        std::cout << _name << " lives.\n";
    }
    ~TestFruit() override { std::cout << _name << " dies.\n"; };
};

int main() {
    FruitBox box(3);
    const FruitBox& cref = box;

    box.pushFruit(new TestFruit("Cerise"));
    box.pushFruit(new TestFruit("Framboise"));
    box.pushFruit(new TestFruit("Anis"));
    std::cout << cref << std::endl;

    IFruit* tmp = new TestFruit("Serge");

    std::cout << box.pushFruit(tmp) << std::endl;
    delete tmp;

    tmp = box.popFruit();
    delete tmp;
    std::cout << cref << std::endl;

    return 0;
}
