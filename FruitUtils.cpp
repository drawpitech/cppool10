/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"

#include <cmath>
#include <span>

void FruitUtils::sort(
    FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry) {
    size_t size = unsorted.getFruits().size();

    for (size_t i = 0; i < size; i++) {
        IFruit *fruit = unsorted.popFruit();
        bool res = false;
        switch (fruit->getType()) {
            case Citrus:
                res = (fruit->getName() == "lemon") ? lemon.pushFruit(fruit)
                                                    : citrus.pushFruit(fruit);
                break;
            case Berry:
                res = berry.pushFruit(fruit);
                break;
            case Nut:
            case Generic:
                res = false;
                break;
        }
        if (!res)
            unsorted.pushFruit(fruit);
    }
}

FruitBox **FruitUtils::pack(IFruit **fruits, unsigned int boxSize) {
    size_t nb_fruits = 0;
    while (fruits[nb_fruits] != nullptr)
        nb_fruits++;

    size_t nb_box = std::ceil(nb_fruits / boxSize);
    auto **res = new FruitBox *[nb_box + 1];

    for (size_t i = 0; i < nb_fruits; i++) {
        if (i % boxSize == 0)
            res[i / boxSize] = new FruitBox(boxSize);
        res[i / boxSize]->pushFruit(fruits[i]);
    }
    res[nb_box] = nullptr;
    return res;
}
