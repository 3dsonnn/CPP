/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:57:03 by efinda            #+#    #+#             */
/*   Updated: 2024/12/11 14:59:15 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cerr << "Error! Run the program using only ./BraiiiiiiinnnzzzZ" << std::endl;
		return (1);
	}
	
	randomChump("stack");

	Zombie	*heap = newZombie("heap");
	delete	heap;

	return (0);
}
