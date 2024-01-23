/*
** EPITECH PROJECT, 2024
** ppool10
** File description:
** Orange
*/

#pragma once

#include "ACitrus.hpp"

class Orange : public ACitrus {
    public:
    Orange(unsigned int vitamins = 7, std::string name = "orange")
        : ACitrus(vitamins, std::move(name)) {}
};
