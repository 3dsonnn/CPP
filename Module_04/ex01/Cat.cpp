/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:45:53 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 15:46:22 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//  Orthodox Canonical Form - start
Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain;
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat   &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        // delete this->brain;
        this->brain = other.brain;
        this->type = other.type;
    }
    return (*this);
}
//  Orthodox Canonical Form - end

void    Cat::makeSound() const   { std::cout << "Meow" << std::endl; }
