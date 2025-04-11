/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:02:52 by efinda            #+#    #+#             */
/*   Updated: 2025/04/09 09:31:25 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class   Fixed
{
    private:
        int                 value;
        static const    int fractionalBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int param);
        Fixed(const float param);
        Fixed(const Fixed &other);
        Fixed   &operator=(const Fixed &other);
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
    // MIN & MAX
        static  Fixed   &min(Fixed &first, Fixed &second);
        static  const   Fixed   &min(const Fixed &first, const Fixed &second);
        static  Fixed   &max(Fixed &first, Fixed &second);
        static  const   Fixed   &max(const Fixed &first, const Fixed &second);
    // Comparison Operators
        bool    operator>(const Fixed &other) const;
        bool    operator<(const Fixed &other) const;
        bool    operator>=(const Fixed &other) const;
        bool    operator<=(const Fixed &other) const;
        bool    operator==(const Fixed &other) const;
        bool    operator!=(const Fixed &other) const;
    // Arithmetic Operators
        Fixed   operator+(const Fixed &other) const;
        Fixed   operator-(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const;
    // (In/De)crement Operators
        Fixed   &operator++(void);
        Fixed   operator++(int);
        Fixed   &operator--(void);
        Fixed   operator--(int);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif