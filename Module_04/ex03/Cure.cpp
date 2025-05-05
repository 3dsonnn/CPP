/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:30:52 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 16:58:46 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//  Orthodox Canonical Form - start
Cure::Cure() { std::cout << "Cure default constructor called" << std::endl; }

Cure::~Cure() { std::cout << "Cure destructor called" << std::endl; }

Cure::Cure(const Cure &other)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = other;
}

Cure   &Cure::operator=(const Cure &other)
{
    (void)other;
    std::cout << "Cure copy assignment operator called" << std::endl;
    return (*this);
}
//  Orthodox Canonical Form - end