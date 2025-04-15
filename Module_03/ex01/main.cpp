/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:02:16 by efinda            #+#    #+#             */
/*   Updated: 2025/04/15 13:24:59 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap    efinda("efinda");
    ScavTrap    ansebast("ansebast");

    efinda.attack("ansebast");
    efinda.takeDamage(3);
    efinda.beRepaired(5);
    efinda.guardGate();

    ansebast.attack("efinda");
    ansebast.takeDamage(42);
    ansebast.beRepaired(7);
    efinda.guardGate();

    return (0);
}
