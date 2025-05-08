/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:29:46 by efinda            #+#    #+#             */
/*   Updated: 2025/05/08 12:54:45 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//  Orthodox Canonical Form - start
Ice::Ice()
{
    this->type = "ice";
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

Ice::Ice(const Ice &other) : AMateria(other) { std::cout << "Ice copy constructor called" << std::endl; }

Ice   &Ice::operator=(const Ice &)
{
    std::cout << "Ice copy assignment operator called" << std::endl;
    return (*this);
}
//  Orthodox Canonical Form - end

Ice *Ice::clone() const { return (new Ice()); }

void    Ice::use(ICharacter &target) { std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }