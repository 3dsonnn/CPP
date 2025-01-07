/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:49:19 by efinda            #+#    #+#             */
/*   Updated: 2024/12/03 10:47:59 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static	void	ft_str_to_upper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		av++;
		while (*av)
		{
			ft_str_to_upper(*av);
			std::cout << *av;
			av++;
		}
		std::cout << std::endl;
	}
	return (0);
}
