/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:09:09 by efinda            #+#    #+#             */
/*   Updated: 2025/04/16 09:52:46 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//  Orthodox Canonical Form - start
ScavTrap::ScavTrap() { /*std::cout << "ScavTrap default constructor called" << std::endl;*/ }

ScavTrap::~ScavTrap() { /*std::cout << "ScavTrap destructor called" << std::endl;*/ }

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) { /*std::cout << "ScavTrap copy constructor called" << std::endl;*/ }

ScavTrap   &ScavTrap::operator=(const ScavTrap &other)
{
    // std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}
//  Orthodox Canonical Form - end

ScavTrap::ScavTrap(std::string arg) : ClapTrap(arg)
{
    // std::cout << "ScavTrap constructor called" << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

void    ScavTrap::attack(const std::string& target)
{
    if (!ClapTrap::getEnergyPoints() || !ClapTrap::getHitPoints())
    {
        std::cout << "ScavTrap " << ClapTrap::getName() << " can't attack due to the lack of energy or hit points" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
    ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
}

void    ScavTrap::guardGate() { std::cout << "ScavTrap is now in Gate keeper mode" << std::endl; }

int ScavTrap::getEnergyPoints(void) { return (50); }

int ScavTrap::getAttackDamage(void) { return (20); }

int ScavTrap::getHitPoints(void) { return (100); }
