/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:47:08 by efinda            #+#    #+#             */
/*   Updated: 2025/04/12 10:16:33 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//  Orthodox Canonical Form - start
Point::Point() : x(0), y(0) { std::cout << "Default constructor called" << std::endl; }

Point::~Point() { std::cout << "Destructor called" << std::endl; }

Point::Point(const Point &other) : x(other.x), y(other.y) { std::cout << "Copy constructor called" << std::endl; }

Point &Point::operator=(const Point &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
    	Point	temp(other);
    	*this = temp;
    }
    return (*this);
}
//  Orthodox Canonical Form - end

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Fixed Point::getCrd(char c) const
{
    if (c == 'x')
        return (this->x);
    if (c == 'y')
        return (this->y);
    return (Fixed(0));
}

bool Point::operator==(Point const &other) const { return ((this->getCrd('x') == other.getCrd('x')) && (this->getCrd('y') == other.getCrd('y'))); }
