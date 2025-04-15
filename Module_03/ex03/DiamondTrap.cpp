/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:21:14 by efinda            #+#    #+#             */
/*   Updated: 2025/04/15 17:30:20 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//  Orthodox Canonical Form - start
DiamondTrap::DiamondTrap() { std::cout << "DiamondTrap default constructor called" << std::endl; }

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor called" << std::endl; }

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap   &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}
//  Orthodox Canonical Form - end 

DiamondTrap::DiamondTrap(std::string arg) : name(arg), FragTrap(arg), ScavTrap(arg) { std::cout << "DiamondTrap constructor called" << std::endl; }

void    DiamondTrap::whoAmI() { std::cout << "DiamondTrap is " << name << " and ClapTrap is " << getName() << std::endl; }
