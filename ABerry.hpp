/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** ABerry
*/

#pragma once

#include "AFruit.hpp"

class ABerry : public AFruit {
   public:
    ABerry(unsigned int vitamins, std::string name)
        : AFruit(vitamins, std::move(name), true) {}
};
