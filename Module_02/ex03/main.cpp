/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:02:55 by efinda            #+#    #+#             */
/*   Updated: 2025/04/12 10:14:45 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

std::ostream    &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

int main( void )
{
    Point   a(0.0f, 0.0f);
    Point   b(4.0f, 0.0f);
    Point   c(2.0f, 3.0f);
    Point   in(2.0f, 1.0f);
    Point   out(4.0f, 3.0f);

    if (bsp(a, b, c, in))
        std::cout << "\t" << "in is inside" << std::endl;
    else
        std::cout << "\t" << "in is outside" << std::endl;
    if (bsp(a, b, c, out))
        std::cout << "\t" << "out is inside" << std::endl;
    else
        std::cout << "\t" << "out is outside" << std::endl;

    // ✅ Strictly inside (should return true):
    Point almostCenter(2, 1.5); // near center
    Point lowInside(1, 0.5);    // close to base but inside
    
    if (bsp(a, b, c, almostCenter))
        std::cout << "\t" << "almostCenter is inside" << std::endl;
    else
        std::cout << "\t" << "almostCenter is outside" << std::endl;
    if (bsp(a, b, c, lowInside))
        std::cout << "\t" << "lowInside is inside" << std::endl;
    else
        std::cout << "\t" << "lowInside is outside" << std::endl;

    // ❌ On the edge (should return false):
    Point onBase(2, 0);      // on edge AB
    Point onLeft(1, 1.5);    // on edge AC
    Point onRight(3, 1.5);   // on edge BC
    
    if (bsp(a, b, c, onBase))
        std::cout << "\t" << "onBase is inside" << std::endl;
    else
        std::cout << "\t" << "onBase is outside" << std::endl;
    if (bsp(a, b, c, onLeft))
        std::cout << "\t" << "onLeft is inside" << std::endl;
    else
        std::cout << "\t" << "onLeft is outside" << std::endl;
    if (bsp(a, b, c, onRight))
        std::cout << "\t" << "onRight is inside" << std::endl;
    else
        std::cout << "\t" << "onRight is outside" << std::endl;
    
    // ❌ On a vertex (should return false):
    Point v1(0, 0); // vertex A
    Point v2(4, 0); // vertex B
    Point v3(2, 3); // vertex C
    
    if (bsp(a, b, c, v1))
        std::cout << "\t" << "v1 is inside" << std::endl;
    else
        std::cout << "\t" << "v1 is outside" << std::endl;
    if (bsp(a, b, c, v2))
        std::cout << "\t" << "v2 is inside" << std::endl;
    else
        std::cout << "\t" << "v2 is outside" << std::endl;
    if (bsp(a, b, c, v3))
        std::cout << "\t" << "v3 is inside" << std::endl;
    else
        std::cout << "\t" << "v3 is outside" << std::endl;

    // ❌ Outside (should return false):
    Point out1(5, 5);      // way outside
    Point out2(2, 3.1);    // just above the triangle
    Point out3(-1, -1);    // bottom left

    if (bsp(a, b, c, out1))
        std::cout << "\t" << "out1 is inside" << std::endl;
    else
        std::cout << "\t" << "out1 is outside" << std::endl;
    if (bsp(a, b, c, out2))
        std::cout << "\t" << "out2 is inside" << std::endl;
    else
        std::cout << "\t" << "out2 is outside" << std::endl;
    if (bsp(a, b, c, out3))
        std::cout << "\t" << "out3 is inside" << std::endl;
    else
        std::cout << "\t" << "out3 is outside" << std::endl;

    return (0);
}
