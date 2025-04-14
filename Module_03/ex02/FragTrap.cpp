/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:11:22 by efinda            #+#    #+#             */
/*   Updated: 2025/04/14 19:17:33 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//  Orthodox Canonical Form - start
FragTrap::FragTrap() : value(0) { std::cout << "Default constructor called" << std::endl; }

FragTrap::~FragTrap() { std::cout << "Destructor called" << std::endl; }

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

FragTrap   &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}
//  Orthodox Canonical Form - end
