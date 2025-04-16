/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:09:09 by efinda            #+#    #+#             */
/*   Updated: 2025/04/16 11:15:36 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//  Orthodox Canonical Form - start
ScavTrap::ScavTrap() : ClapTrap() { std::cout << "ScavTrap default constructor called" << std::endl; }

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) { std::cout << "ScavTrap copy constructor called" << std::endl; }

ScavTrap   &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}
//  Orthodox Canonical Form - end

ScavTrap::ScavTrap(std::string arg) : ClapTrap(arg)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

void    ScavTrap::attack(const std::string& target)
{
    if (!energyPoints || !hitPoints)
    {
        std::cout << "ScavTrap " << name << " can't attack due to the lack of energy or hit points" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void    ScavTrap::guardGate() { std::cout << "ScavTrap is now in Gate keeper mode" << std::endl; }
