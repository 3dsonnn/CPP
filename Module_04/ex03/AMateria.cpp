/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:06:10 by efinda            #+#    #+#             */
/*   Updated: 2025/05/08 12:21:28 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//  Orthodox Canonical Form - start
AMateria::AMateria() { std::cout << "AMateria default constructor called" << std::endl; }

AMateria::~AMateria() { std::cout << "AMateria destructor called" << std::endl; }

AMateria::AMateria(const AMateria &) { std::cout << "AMateria copy constructor called" << std::endl; }

AMateria   &AMateria::operator=(const AMateria &)
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
    return (*this);
}
//  Orthodox Canonical Form - end

AMateria::AMateria(std::string const &type) : type(type) {}

std::string const &AMateria::getType() const { return (type); }

void AMateria::use(ICharacter &) { }