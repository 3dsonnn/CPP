/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:21:14 by efinda            #+#    #+#             */
/*   Updated: 2025/04/16 12:26:56 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//  Orthodox Canonical Form - start
DiamondTrap::DiamondTrap() { std::cout << "DiamondTrap default constructor called" << std::endl; }

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor called" << std::endl; }

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(), FragTrap(), ScavTrap(other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    this->name = other.name;
}

DiamondTrap   &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    return (*this);
}
//  Orthodox Canonical Form - end 

DiamondTrap::DiamondTrap(std::string arg) : ClapTrap(arg + "_clap_name"), name(arg)
{
    std::cout << "DiamondTrap constructor called" << std::endl;
    attackDamage = 30;
    hitPoints = 100;
}

void    DiamondTrap::whoAmI() { std::cout << "DiamondTrap is " << this->name << " and ClapTrap is " << ClapTrap::name << std::endl; }
