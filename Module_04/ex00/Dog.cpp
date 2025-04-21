/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:45:26 by efinda            #+#    #+#             */
/*   Updated: 2025/04/17 12:45:28 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//  Orthodox Canonical Form - start
Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog   &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}
//  Orthodox Canonical Form - end

std::string Dog::getType() const   { return (this->type); }

void    Dog::makeSound() const { std::cout << "Woof" << std::endl; }