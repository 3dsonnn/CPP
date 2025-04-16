/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:14:46 by efinda            #+#    #+#             */
/*   Updated: 2025/04/15 21:19:40 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class   ScavTrap :  virtual public ClapTrap
{
    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(std::string arg);
        ScavTrap(const ScavTrap &other);
        ScavTrap    &operator=(const ScavTrap &other);
        void        attack(const std::string& target);
        void        guardGate();
        int         getEnergyPoints(void);
        int         getAttackDamage(void);
        int         getHitPoints(void);
};

#endif