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

//  Orthodox Canonical Form - start
Fixed::Fixed() : value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed   &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}
//  Orthodox Canonical Form - end

int Fixed::getRawBits( void ) const { return (this->value); }

void Fixed::setRawBits( int const raw ) { this->value = raw; }

Fixed::Fixed(const int param)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(param * 256);
}

Fixed::Fixed(const float param)
{
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits((int)roundf(param * 256));
}

float   Fixed::toFloat( void ) const { return (this->getRawBits() / 256.0f); }

int     Fixed::toInt( void ) const { return (this->getRawBits() / 256); }

// MIN & MAX
Fixed   &Fixed::min(Fixed &first, Fixed &second) { return ((first < second) ? first : second); }

const   Fixed   &Fixed::min(const Fixed &first, const Fixed &second) { return ((first < second) ? first : second); }

Fixed   &Fixed::max(Fixed &first, Fixed &second) { return ((first > second) ? first : second); }

const   Fixed   &Fixed::max(const Fixed &first, const Fixed &second) { return ((first > second) ? first : second); }

// Comparison Operators
bool    Fixed::operator>(const Fixed &other) const { return (this->getRawBits() > other.getRawBits()); }

bool    Fixed::operator<(const Fixed &other) const { return (this->getRawBits() < other.getRawBits()); }

bool    Fixed::operator>=(const Fixed &other) const { return (this->getRawBits() >= other.getRawBits()); }

bool    Fixed::operator<=(const Fixed &other) const { return (this->getRawBits() <= other.getRawBits()); }

bool    Fixed::operator==(const Fixed &other) const { return (this->getRawBits() == other.getRawBits()); }

bool    Fixed::operator!=(const Fixed &other) const { return (this->getRawBits() != other.getRawBits()); }

// Arithmetic Operators
Fixed   Fixed::operator+(const Fixed &other) const
{
    Fixed   tmp;

    tmp.setRawBits(this->getRawBits() + other.getRawBits());
    return (tmp);
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    Fixed   tmp;

    tmp.setRawBits(this->getRawBits() - other.getRawBits());
    return (tmp);
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    Fixed   tmp;

    tmp.setRawBits((this->getRawBits() * other.getRawBits()) / 256);
    return (tmp);
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    Fixed   tmp;

    tmp.setRawBits((this->getRawBits() * 256) / other.getRawBits());
    return (tmp);
}

// (In/De)crement Operators
Fixed   &Fixed::operator++(void)
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   tmp(*this);

    ++(*this);
    return (tmp);
}

Fixed   &Fixed::operator--(void)
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed   tmp(*this);

    --(*this);
    return (tmp);
}
