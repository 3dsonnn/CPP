/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:45:26 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 16:02:01 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
//  Orthodox Canonical Form - start
Dog::Dog()
{
    type = "Dog";
    brain = new Brain;
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog   &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        // delete this->brain;
        this->type = other.type;
        this->brain = other.brain;
    }
    return (*this);
}
//  Orthodox Canonical Form - end

void    Dog::makeSound() const { std::cout << "Woof" << std::endl; }