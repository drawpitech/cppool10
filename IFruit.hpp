/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** IFruit
*/

#pragma once

#include <string>

class IFruit {
   public:
    IFruit() = default;
    virtual ~IFruit() = default;

    [[nodiscard]] virtual unsigned int getVitamins() const = 0;
    [[nodiscard]] virtual std::string getName() const = 0;
    [[nodiscard]] virtual bool isPeeled() const = 0;
    virtual void peel() = 0;
};

std::ostream &operator<<(std::ostream &os, const IFruit &fruit);
