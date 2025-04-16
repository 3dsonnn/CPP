/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:11:22 by efinda            #+#    #+#             */
/*   Updated: 2025/04/16 11:22:50 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//  Orthodox Canonical Form - start
FragTrap::FragTrap() : ClapTrap() { std::cout << "FragTrap default constructor called" << std::endl; }

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) { std::cout << "FragTrap copy constructor called" << std::endl; }

FragTrap   &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}
//  Orthodox Canonical Form - end

FragTrap::FragTrap(std::string arg) : ClapTrap(arg)
{
    std::cout << "FragTrap constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

void    FragTrap::highFivesGuys(void) { std::cout << "FragTrap request the highest of the fives" << std::endl; }
