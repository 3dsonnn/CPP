/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:29:46 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 16:30:34 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//  Orthodox Canonical Form - start
Ice::Ice() { std::cout << "Ice default constructor called" << std::endl; }

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

Ice::Ice(const Ice &other)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = other;
}

Ice   &Ice::operator=(const Ice &other)
{
    (void)other;
    std::cout << "Ice copy assignment operator called" << std::endl;
    return (*this);
}
//  Orthodox Canonical Form - end