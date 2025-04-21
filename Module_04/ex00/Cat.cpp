/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:45:53 by efinda            #+#    #+#             */
/*   Updated: 2025/04/17 12:45:54 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//  Orthodox Canonical Form - start
Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat   &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}
//  Orthodox Canonical Form - end

std::string Cat::getType() const   { return (this->type); }

void    Cat::makeSound() const   { std::cout << "Meow" << std::endl; }
