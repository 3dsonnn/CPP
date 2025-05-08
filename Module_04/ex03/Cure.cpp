/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:30:52 by efinda            #+#    #+#             */
/*   Updated: 2025/05/08 12:54:43 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//  Orthodox Canonical Form - start
Cure::Cure()
{
    this->type = "cure";
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure() { std::cout << "Cure destructor called" << std::endl; }

Cure::Cure(const Cure &other) : AMateria(other) { std::cout << "Cure copy constructor called" << std::endl; }

Cure   &Cure::operator=(const Cure &)
{
    std::cout << "Cure copy assignment operator called" << std::endl;
    return (*this);
}
//  Orthodox Canonical Form - end

Cure *Cure::clone() const { return (new Cure()); }

void    Cure::use(ICharacter &target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }