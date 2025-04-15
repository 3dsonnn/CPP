/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 07:42:42 by efinda            #+#    #+#             */
/*   Updated: 2025/04/15 09:47:31 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap    efinda("efinda");
    ClapTrap    ansebast("ansebast");

    efinda.attack("ansebast");
    efinda.takeDamage(3);
    efinda.beRepaired(5);

    ansebast.attack("efinda");
    ansebast.takeDamage(42);
    ansebast.beRepaired(7);

    return (0);
}