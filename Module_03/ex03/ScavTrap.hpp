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

    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap   &operator=(const ScavTrap &other);
};

#endif