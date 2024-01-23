/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** AFruit
*/

#include "IFruit.hpp"

#include <iostream>

std::ostream &operator<<(std::ostream &os, const IFruit &fruit) {
    return os << "[name: \"" << fruit.getName()
              << "\", vitamins: " << fruit.getVitamins()
              << ", peeled: " << (fruit.isPeeled() ? "true" : "false") << "]";
}
