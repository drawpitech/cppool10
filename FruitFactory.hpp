/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** FruitFactory
*/

#pragma once

#include <algorithm>
#include <vector>

#include "IFruit.hpp"

class FruitFactory {
   public:
    ~FruitFactory() {
        size_t size = _fruits.size();
        while (size-- != 0) {
            delete _fruits.back();
            _fruits.pop_back();
        }
            
    }

    void registerFruit(IFruit* fruit) { _fruits.push_back(fruit); }
    void unregisterFruit(const std::string& name) {
        auto lambda = [&name](IFruit* f) { return f->getName() == name; };
        auto idx = std::find_if(_fruits.begin(), _fruits.end(), lambda);

        if (idx != _fruits.end()) {
            delete *idx;
            _fruits.erase(idx);
        }
    }
    [[nodiscard]] IFruit* createFruit(const std::string& name) const {
        auto lambda = [&name](IFruit* f) { return f->getName() == name; };
        auto idx = std::find_if(_fruits.begin(), _fruits.end(), lambda);

        if (idx == _fruits.end())
            return nullptr;
        return (*idx)->clone();
    }

   private:
    std::vector<IFruit*> _fruits;
};
