/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:57:03 by efinda            #+#    #+#             */
/*   Updated: 2024/12/10 07:57:04 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error! Run the program using only <./moarBrainz\\!> <name>" << std::endl;
		return (1);
	}
	int	i = -1;
	Zombie	*horde = zombieHorde(42, *(av + 1));

	while (++i < 42)
		horde[i].announce();
	delete[] horde;
	return (0);
}
