/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:02:55 by efinda            #+#    #+#             */
/*   Updated: 2025/04/09 09:29:02 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream    &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

int main( void )
{
    /*std::cout << "*** SUBJECT TESTS ***" << std::endl;
    Fixed   a;
    Fixed   const   b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << "\t" << a << std::endl;
    std::cout << "\t" << ++a << std::endl;
    std::cout << "\t" << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << "\t" << a << std::endl;
    std::cout << "\t" << b << std::endl;
    std::cout << "\t" << Fixed::max( a, b ) << std::endl;

    std::cout << std::endl << "*** MAX & MIN ***" << std::endl;
    Fixed   c(5.5f);
    Fixed   d(10.25f);
    Fixed& minRef = Fixed::min(c, d);
    Fixed& maxRef = Fixed::max(c, d);
    std::cout << "\t" << "Min: " << minRef << std::endl;
    std::cout << "\t" << "Max: " << maxRef << std::endl;

    std::cout << std::endl << "*** COMPARISON OPERATORS ***" << std::endl;
    Fixed   e(5.5f);
    Fixed   f(10.25f);
    Fixed   g;
    g = e;
    if (e >= f)
        std::cout << "\t" << e << " >= " << f << std::endl;
    else
        std::cout << "\t" << e << " < " << f << std::endl;
    if (f <= g)
        std::cout << "\t" << f << " <= " << g << std::endl;
    else
        std::cout << "\t" << f << " > " << g << std::endl;
    if (g == e)
        std::cout << "\t" << g << " == " << e << std::endl;
    else
        std::cout << "\t" << g << " != " << e << std::endl;
    if (g != f)
        std::cout << "\t" << g << " != " << f << std::endl;
    else
        std::cout << "\t" << g << " == " << f << std::endl;

    std::cout << std::endl << "*** ARITHMETIC OPERATORS ***" << std::endl;
    Fixed   h = Fixed( 21 ) + Fixed( 21 );
    std::cout << "\t" << "21 + 21 = " << h << std::endl;
    h = Fixed( 63 ) - Fixed( 21 );
    std::cout << "\t" << "63 - 21 = " << h << std::endl;
    h = Fixed( 21 ) * Fixed( 2 );
    std::cout << "\t" << "21 * 2 = " << h << std::endl;
    h = Fixed( 126 ) / Fixed( 3 );
    std::cout << "\t" << "126 / 3 = " << h << std::endl;*/

    std::cout << std::endl << "*** (IN/DE)CREMENT OPERATORS ***" << std::endl;
    Fixed   i = Fixed( 43 );
    std::cout << "\t" << "Fixed Point ++43 = " << ++i << std::endl;
    i = Fixed( 43 );
    std::cout << "\t" << "Fixed Point 43--" << std::endl;
    std::cout << i-- << std::endl;
    std::cout << "\t" << i << std::endl;

    return (0);
}
