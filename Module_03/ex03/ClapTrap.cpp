/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:57:01 by efinda            #+#    #+#             */
/*   Updated: 2025/04/15 17:28:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//  Orthodox Canonical Form - start
ClapTrap::ClapTrap() { std::cout << "ClapTrap default constructor called" << std::endl; }

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap   &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}
//  Orthodox Canonical Form - end

ClapTrap::ClapTrap(std::string arg) : name(arg), hitPoints(100), energyPoints(100), attackDamage(30) { std::cout << "ClapTrap constructor called" << std::endl; }

std::string ClapTrap::getName(void) const { return (name); }

void    ClapTrap::attack(const std::string& target)
{
    if (!this->energyPoints || !this->hitPoints)
    {
        std::cout << "ClapTrap " << this->name << " can't attack due to the lack of energy or hit points" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (!this->energyPoints || !this->hitPoints)
    {
        std::cout << "ClapTrap " << this->name << " can't take damage due to the lack of energy or hit points" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " took a damage of " << amount << std::endl;
    this->hitPoints -= amount;
    if (this->hitPoints < 0)
        this->hitPoints = 0;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->energyPoints || !this->hitPoints)
    {
        std::cout << "ClapTrap " << this->name << " can't repaired itself due to the lack of energy or hit points" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " repaired itself, regaining " << amount << " hit points" << std::endl;
    this->energyPoints--;
    this->hitPoints += amount;
}
