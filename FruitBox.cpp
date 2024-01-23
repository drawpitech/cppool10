/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** AFruit
*/

#include "FruitBox.hpp"

#include <iostream>

std::ostream &operator<<(std::ostream &os, const FruitBox &box) {
    os << "[";
    auto fruits = box.getFruits();
    if (!fruits.empty()) {
        os << *fruits.at(0);
        for (size_t i = 1; i < fruits.size(); i++)
            os << ", " << *fruits.at(i);
    }
    return os << "]";
}
