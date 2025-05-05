/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:06:10 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 16:13:52 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//  Orthodox Canonical Form - start
AMateria::AMateria() { std::cout << "AMateria default constructor called" << std::endl; }

AMateria::~AMateria() { std::cout << "AMateria destructor called" << std::endl; }

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = other;
}

AMateria   &AMateria::operator=(const AMateria &other)
{
    (void)other;
    std::cout << "AMateria copy assignment operator called" << std::endl;
    return (*this);
}
//  Orthodox Canonical Form - end

std::string AMateria::getType() const { return (type); }