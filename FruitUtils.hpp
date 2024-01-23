/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** FruitUtils
*/

#pragma once

#include "FruitBox.hpp"

class FruitUtils {
   public:
    FruitUtils() = default;
    void sort(
        FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus,
        FruitBox &berry) {
        size_t size = unsorted.getFruits().size();

        for (size_t i = 0; i < size; i++) {
            IFruit *fruit = unsorted.popFruit();
            bool res = false;
            switch (fruit->getType()) {
                case Citrus:
                    res = citrus.pushFruit(fruit);
                    break;
                case Berry:
                    res = (fruit->getName() == "lemon")
                              ? lemon.pushFruit(fruit)
                              : berry.pushFruit(fruit);
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
};
