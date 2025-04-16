/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:21:36 by efinda            #+#    #+#             */
/*   Updated: 2025/04/15 21:22:50 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class   DiamondTrap :   public FragTrap, public ScavTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        ~DiamondTrap();
        DiamondTrap(std::string arg);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap &operator=(const DiamondTrap &other);
        void        attack(const std::string& target);
        void        whoAmI();
};

#endif