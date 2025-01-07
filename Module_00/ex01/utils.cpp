/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:23:20 by efinda            #+#    #+#             */
/*   Updated: 2024/12/08 15:25:02 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	print_truncated(const std::string str)
{
	int	i;
	
	i = -1;
	if (strlen(str.c_str()) > 10)
	{
		while (++i < 9)
			std::cout << str[i];
		std::cout << '.';
	}
	else
		std::cout << std::setw(10) << std::right << str;
}

int	check_name(const std::string str)
{
	int	i;
	
	i = -1;
	while (str[++i])
	{
		if (!isalpha(str[i]))
		{
			std::cerr << NONAME;
			return (1);
		}
	}
	return (0);
}

int	ft_strnbr(const char *str)
{
	int	i;

	i = 0;
	if (!str || !(*str))
		return (1);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (1);
	while (isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}
