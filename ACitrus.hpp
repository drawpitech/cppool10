/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** ACitrus
*/

#pragma once

#include "AFruit.hpp"

class ACitrus : public AFruit {
   public:
    ACitrus(unsigned int vitamins, std::string name)
        : AFruit(vitamins, std::move(name), false) {}
};
