/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:46:47 by efinda            #+#    #+#             */
/*   Updated: 2025/04/12 09:27:47 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point();
    ~Point();
    Point(const Point &other);
    Point   &operator=(const Point &other);
    bool    operator==(Point const &other) const;
    Point(const float x, const float y);
    Fixed getCrd(char c) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif