/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:47:24 by efinda            #+#    #+#             */
/*   Updated: 2025/04/12 09:49:55 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed distanceBetweenTwoPoints(Point const p1, Point const p2)
{
    Fixed dx = p2.getCrd('x') - p1.getCrd('x');
    Fixed dy = p2.getCrd('y') - p1.getCrd('y');
    Fixed aux = (dx * dx) + (dy * dy);
    return (Fixed(std::sqrt(aux.toFloat())));
}

static Fixed HeronTriangleArea(Fixed sideA, Fixed sideB, Fixed sideC)
{
    Fixed semiPerimeter = (sideA + sideB + sideC) / Fixed(2);
    Fixed aux = semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC);
    return (Fixed(std::sqrt(aux.toFloat())));
}

static Fixed absFixed(Fixed const &value) { return (value < Fixed(0)) ? value * Fixed(-1) : value; }

static bool isOnEdge(Point const &p, Point const &x, Point const &y)
{
    Fixed area = HeronTriangleArea(
        distanceBetweenTwoPoints(p, x),
        distanceBetweenTwoPoints(x, y),
        distanceBetweenTwoPoints(y, p));

    if (absFixed(area) > Fixed(0.01f))
        return (false);
    Fixed xMin = (x.getCrd('x') < y.getCrd('x')) ? x.getCrd('x') : y.getCrd('x');
    Fixed xMax = (x.getCrd('x') > y.getCrd('x')) ? x.getCrd('x') : y.getCrd('x');
    Fixed yMin = (x.getCrd('y') < y.getCrd('y')) ? x.getCrd('y') : y.getCrd('y');
    Fixed yMax = (x.getCrd('y') > y.getCrd('y')) ? x.getCrd('y') : y.getCrd('y');
    return (p.getCrd('x') >= xMin && p.getCrd('x') <= xMax &&
        p.getCrd('y') >= yMin && p.getCrd('y') <= yMax);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if (point == a || point == b || point == c)
        return (false);
    if (isOnEdge(point, a, b) || isOnEdge(point, b, c) || isOnEdge(point, c, a))
        return (false);
    Fixed mainArea = HeronTriangleArea(
        distanceBetweenTwoPoints(a, b),
        distanceBetweenTwoPoints(b, c),
        distanceBetweenTwoPoints(c, a));
    Fixed firstArea = HeronTriangleArea(
        distanceBetweenTwoPoints(point, b),
        distanceBetweenTwoPoints(b, c),
        distanceBetweenTwoPoints(c, point));
    Fixed secondArea = HeronTriangleArea(
        distanceBetweenTwoPoints(a, point),
        distanceBetweenTwoPoints(point, c),
        distanceBetweenTwoPoints(c, a));
    Fixed thirdArea = HeronTriangleArea(
        distanceBetweenTwoPoints(a, b),
        distanceBetweenTwoPoints(b, point),
        distanceBetweenTwoPoints(point, a));
    return ((firstArea + secondArea + thirdArea) <= mainArea);
}
