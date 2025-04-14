/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:09:09 by efinda            #+#    #+#             */
/*   Updated: 2025/04/14 19:09:15 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//  Orthodox Canonical Form - start
ScavTrap::ScavTrap() : value(0) { std::cout << "Default constructor called" << std::endl; }

ScavTrap::~ScavTrap() { std::cout << "Destructor called" << std::endl; }

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ScavTrap   &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}
//  Orthodox Canonical Form - end
