/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:21:14 by efinda            #+#    #+#             */
/*   Updated: 2025/04/14 19:40:44 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//  Orthodox Canonical Form - start
DiamondTrap::DiamondTrap() : value(0) { std::cout << "Default constructor called" << std::endl; }

DiamondTrap::~DiamondTrap() { std::cout << "Destructor called" << std::endl; }

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap   &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}
//  Orthodox Canonical Form - end 