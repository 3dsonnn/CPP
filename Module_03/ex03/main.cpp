/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:02:16 by efinda            #+#    #+#             */
/*   Updated: 2025/04/16 09:59:27 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap    efinda("efinda");
    DiamondTrap    ansebast("ansebast");

    efinda.attack("ansebast");
    efinda.takeDamage(3);
    efinda.beRepaired(5);
    efinda.guardGate();
    efinda.highFivesGuys();
    efinda.whoAmI();

    ansebast.attack("efinda");
    ansebast.takeDamage(42);
    ansebast.beRepaired(7);
    ansebast.guardGate();
    ansebast.highFivesGuys();
    ansebast.whoAmI();

    return (0);
}
