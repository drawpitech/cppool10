#include <iostream>

#include "../Almond.hpp"
#include "../Orange.hpp"
#include "../Strawberry.hpp"

int main() {
    Orange o;
    Strawberry s;
    const Almond a;
    IFruit &f = o;

    std::cout << o.getName() << ": " << o.getVitamins() << " vitamins"
              << std::endl;
    std::cout << s << std::endl;
    std::cout << a << std::endl;
    o.peel();
    std::cout << f << std::endl;
    return 0;
}
