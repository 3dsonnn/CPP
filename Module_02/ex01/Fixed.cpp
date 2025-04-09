/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:02:49 by efinda            #+#    #+#             */
/*   Updated: 2025/04/09 09:34:30 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const int param)
{
    this->value = other.value;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const float param)
{
    this->value = other.value;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    this->value = other.value;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed   &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->setRawBits(other.getRawBits());
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
    std::cout << "setRawBits member function called" << std::endl;
}
