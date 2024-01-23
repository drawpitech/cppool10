/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"

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
