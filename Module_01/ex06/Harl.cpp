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
			switch (i)
			{
				case 0:
					(this->*ft_ptr_tab[0])();
					(this->*ft_ptr_tab[1])();
					(this->*ft_ptr_tab[2])();
					(this->*ft_ptr_tab[3])();
					break ;
				case 1:
					(this->*ft_ptr_tab[1])();
					(this->*ft_ptr_tab[2])();
					(this->*ft_ptr_tab[3])();
					break ;
				case 2:
					(this->*ft_ptr_tab[2])();
					(this->*ft_ptr_tab[3])();
					break ;
				case 3:
					(this->*ft_ptr_tab[3])();
					break ;
				default:
					std::cerr << "Error! \"" << level << "\" is not a valid level" << std::endl;
					exit(1);
			}
			exit(0);
		}
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << DEBUG << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << INFO << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl <<  WARNING << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl <<  ERROR << std::endl;
}
