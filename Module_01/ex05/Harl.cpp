/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:29:23 by efinda            #+#    #+#             */
/*   Updated: 2024/12/12 03:29:24 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	int	i = -1;
	typedef	void	(Harl::*HarlPtr)();

	std::string	tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HarlPtr	ft_ptr_tab[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	while (++i < 4)
	{
		if (level.compare(tab[i]) == 0)
		{
			(this->*ft_ptr_tab[i])();
			exit(0);
		}
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << DEBUG;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << INFO;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl <<  WARNING;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl <<  ERROR;
}
