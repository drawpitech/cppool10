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
    static void sort(
        FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry);
    static FruitBox **pack(IFruit **fruits, unsigned int boxSize);
};
