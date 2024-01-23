/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** AFruit
*/

#pragma once

#include "IFruit.hpp"

class AFruit : public virtual IFruit {
   public:
    AFruit(
        unsigned int vitamins, std::string name, bool peeled,
        FruitType type = Generic)
        : _vitamins(vitamins),
          _name(std::move(name)),
          _peeled(peeled),
          _type(type) {}

    [[nodiscard]] unsigned int getVitamins() const override {
        return _peeled ? _vitamins : 0;
    }
    [[nodiscard]] std::string getName() const override { return _name; }
    [[nodiscard]] bool isPeeled() const override { return _peeled; }
    [[nodiscard]] FruitType getType() const override { return _type; }

    void peel() override { _peeled = true; }

    [[nodiscard]] IFruit *clone() const override { return new AFruit(*this); }

   protected:
    unsigned int _vitamins;
    std::string _name;
    bool _peeled;
    FruitType _type;
};
