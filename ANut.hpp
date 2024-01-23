/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** ANut
*/

#pragma once

#include "AFruit.hpp"

class ANut : public AFruit {
   public:
    ANut(unsigned int vitamins, std::string name)
        : AFruit(vitamins, std::move(name), false, Nut) {}
};
