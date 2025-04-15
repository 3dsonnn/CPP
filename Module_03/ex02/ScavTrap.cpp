/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:09:09 by efinda            #+#    #+#             */
/*   Updated: 2025/04/15 13:25:06 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//  Orthodox Canonical Form - start
ScavTrap::ScavTrap() { std::cout << "ScavTrap default constructor called" << std::endl; }

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

ScavTrap::ScavTrap(std::string arg) : ClapTrap(arg) { std::cout << "ScavTrap constructor called" << std::endl; }

void    ScavTrap::guardGate() { std::cout << "ScavTrap is now in Gate keeper mode" << std::endl; }
