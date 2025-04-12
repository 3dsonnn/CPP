/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:14:46 by efinda            #+#    #+#             */
/*   Updated: 2025/04/12 11:15:00 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class   ScavTrap
{
    private:
        int                 value;
        static const    int fractionalBits = 8;
    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(const int param);
        ScavTrap(const float param);
        ScavTrap(const ScavTrap &other);
        ScavTrap   &operator=(const ScavTrap &other);
        float   toFloat( void ) const;
        int     toInt( void ) const;
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& out, const ScavTrap& ScavTrap);

#endif