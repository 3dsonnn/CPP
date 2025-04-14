/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:21:36 by efinda            #+#    #+#             */
/*   Updated: 2025/04/14 19:22:23 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>

class   DiamondTrap
{
    private:
        
    public:
        DiamondTrap();
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap   &operator=(const DiamondTrap &other);
};

#endif