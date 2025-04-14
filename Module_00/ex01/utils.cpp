/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:23:20 by efinda            #+#    #+#             */
/*   Updated: 2025/04/12 16:52:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void print_truncated(const std::string str)
{
	int i = -1;

	if (str.size() > 10)
	{
		while (++i < 9)
			std::cout << str.at(i);
		std::cout << '.';
	}
	else
		std::cout << std::setw(10) << std::right << str;
}

int check_name(const std::string str)
{
	if (str.empty())
		return (std::cerr << EMPTY, 1);
	for (int i = 0; i < (int)str.size(); i++)
		if (!std::isalpha(str.at(i)))
			return (std::cerr << NONAME, 1);
	return (0);
}

int my_getline(std::string &str)
{
	if (!std::getline(std::cin, str))
		return (std::cerr << EOF << std::endl, 1);
	return (0);
}

int ft_strnbr(const char *str)
{
	int i = 0;

	if (!str || !(*str))
		return (1);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (isdigit(str[i]))
		i++;
	if (!str[i])
		return (0);
	return (1);
}
