/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:42:52 by efinda            #+#    #+#             */
/*   Updated: 2025/04/17 15:45:43 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//  Orthodox Canonical Form - start
Animal::Animal() { std::cout << "Animal default constructor called" << std::endl; }

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal   &Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}
//  Orthodox Canonical Form - end
