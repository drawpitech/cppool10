/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** FruitBox
*/

#pragma once

#include <iostream>
#include <vector>

#include "IFruit.hpp"

class FruitBox {
   public:
    FruitBox(unsigned int size) : _sizeMax(size) {}
    ~FruitBox() {
        while (!_fruits.empty())
            delete popFruit();
    }

    [[nodiscard]] unsigned int getSize() const { return _sizeMax; }
    [[nodiscard]] unsigned int nbFruits() const { return _fruits.size(); }
    [[nodiscard]] std::vector<IFruit *> getFruits() const { return _fruits; }

    bool pushFruit(IFruit *fruit) {
        if (_fruits.size() == _sizeMax)
            return false;
        for (auto &f : _fruits)
            if (f == fruit)
                return false;
        _fruits.insert(_fruits.end(), fruit);
        return true;
    }
    IFruit *popFruit() {
        if (_fruits.empty())
            return nullptr;

        IFruit *fruit = _fruits.front();
        _fruits.erase(_fruits.begin(), _fruits.begin() + 1);
        return fruit;
    }

   private:
    unsigned int _sizeMax;
    std::vector<IFruit *> _fruits;
};

std::ostream &operator<<(std::ostream &os, const FruitBox &box);
