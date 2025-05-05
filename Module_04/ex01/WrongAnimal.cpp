/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:54:12 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 11:50:15 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//  Orthodox Canonical Form - start
WrongAnimal::WrongAnimal() : type("WrongAnimal") { std::cout << "WrongAnimal default constructor called" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal   &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}
//  Orthodox Canonical Form - end

std::string WrongAnimal::getType() const   { return (type); }

void    WrongAnimal::makeSound() const { std::cout << "WrongAnimal" << std::endl; }