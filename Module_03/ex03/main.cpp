/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:02:16 by efinda            #+#    #+#             */
/*   Updated: 2025/04/15 17:08:26 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void )
{
    FragTrap    efinda("efinda");
    FragTrap    ansebast("ansebast");

    efinda.attack("ansebast");
    efinda.takeDamage(3);
    efinda.beRepaired(5);
    efinda.highFivesGuys();

    ansebast.attack("efinda");
    ansebast.takeDamage(42);
    ansebast.beRepaired(7);
    efinda.highFivesGuys();

    return (0);
}
