/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:29:32 by efinda            #+#    #+#             */
/*   Updated: 2024/12/12 03:29:32 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error! Run using only ./ex05 <level>" << std::endl;
		return (1);
	}
	Harl	harl;

	harl.complain(*(av + 1));

	std::cerr << "Error! \"" << *(av + 1) << "\" is not a valid level" << std::endl;

	return (1);
}
