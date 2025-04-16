/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:55:47 by efinda            #+#    #+#             */
/*   Updated: 2025/04/16 11:06:01 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class   ClapTrap
{
    protected:
        std::string name;
        int         hitPoints;
        int         energyPoints;
        int         attackDamage;
    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(std::string arg);
        ClapTrap(const ClapTrap &other);
        ClapTrap    &operator=(const ClapTrap &other);
        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};

#endif
