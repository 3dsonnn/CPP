/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:21:14 by efinda            #+#    #+#             */
/*   Updated: 2025/04/16 09:51:43 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//  Orthodox Canonical Form - start
DiamondTrap::DiamondTrap() { /*std::cout << "DiamondTrap default constructor called" << std::endl;*/ }

DiamondTrap::~DiamondTrap() { /*std::cout << "DiamondTrap destructor called" << std::endl;*/ }

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    // std::cout << "DiamondTrap copy constructor called" << std::endl;
    this->name = other.name;
}

DiamondTrap   &DiamondTrap::operator=(const DiamondTrap &other)
{
    // std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        this->name = other.name;
    }
    return (*this);
}
//  Orthodox Canonical Form - end 

void    DiamondTrap::attack(const std::string& target) { ScavTrap::attack(target); }

DiamondTrap::DiamondTrap(std::string arg) : ClapTrap(arg + "_clap_name"), FragTrap(), ScavTrap(), name(arg)
{
    // std::cout << "DiamondTrap constructor called" << std::endl;
    setEnergyPoints(ScavTrap::getEnergyPoints());
    setAttackDamage(FragTrap::getAttackDamage());
    setHitPoints(FragTrap::getHitPoints());
}

void    DiamondTrap::whoAmI() { std::cout << "DiamondTrap is " << name << " and ClapTrap is " << getName() << std::endl; }
