/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:42:52 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 16:00:26 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//  Orthodox Canonical Form - start
AAnimal::AAnimal() { std::cout << "AAnimal default constructor called" << std::endl; }

AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = other;
}

AAnimal   &AAnimal::operator=(const AAnimal &other)
{
    (void)other;
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    return (*this);
}
//  Orthodox Canonical Form - end

std::string AAnimal::getType() const { return (type); }