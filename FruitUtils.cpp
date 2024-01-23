/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"

#include <cmath>

#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "ANut.hpp"

static FruitType deduce_type(IFruit *fruit) {
    if (dynamic_cast<ACitrus *>(fruit) != nullptr)
        return Citrus;
    if (dynamic_cast<ABerry *>(fruit) != nullptr)
        return Berry;
    if (dynamic_cast<ANut *>(fruit) != nullptr)
        return Nut;
    return Generic;
}

void FruitUtils::sort(
    FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry) {
    size_t size = unsorted.getFruits().size();

    for (size_t i = 0; i < size; i++) {
        IFruit *fruit = unsorted.popFruit();
        bool res = false;

        switch (deduce_type(fruit)) {
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
