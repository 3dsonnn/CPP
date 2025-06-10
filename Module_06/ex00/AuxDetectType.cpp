/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AuxDetectType.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:31:33 by efinda            #+#    #+#             */
/*   Updated: 2025/06/04 17:05:33 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aux.hpp"

static int	charCount(std::string str, const char c)
{
    int res = 0;

	for (size_t i = 0; i < str.size(); i++)
		if (str.at(i) == c)
	        res++;
	return (res);
}

static int	isInt(std::string str)
{
	size_t i = (str.at(0) == '+' || str.at(0) == '-') ? 1 : 0;
	if (i && !isdigit(str.at(i)))
		return (i);
	while (i < str.size())
	{
		if (!isdigit(str.at(i)))
	        return (1);
		i++;
	}
	return (0);
}

static int	isFloat(std::string str)
{
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
        return (0);
    if (str.at(str.size() - 1) != 'f' || charCount(str, '.') != 1 /*|| (str.at(str.size() - 1) == 'f'
		&& !(str.at(str.size() - 2) >= '0' && str.at(str.size() - 2) <= '9'))*/)
		return (1);
    str.erase(str.size() - 1, 1);
    if (str.at(0) == '+' || str.at(0) == '-')
        str.erase(0, 1);
    if (str.empty() || !str.compare("."))
		return (1);
	for (size_t i = 0; i < str.size(); i++)
		if (!(isdigit(str.at(i)) || str.at(i) == '.'))
	        return (1);
	return (0);
}

static int	isDouble(std::string str)
{
    if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return (0);
	if (charCount(str, '.') != 1/* || str.at(str.size() - 1) == '.'*/)
        return (1);
    if (str.at(0) == '+' || str.at(0) == '-')
        str.erase(0, 1);
    if (str.empty() || !str.compare("."))
		return (1);
	for (size_t i = 0; i < str.size(); i++)
		if (!(isdigit(str.at(i)) || str.at(i) == '.'))
	        return (1);
	return (0);
}

void	detectType(std::string literal, t_type &type)
{
	if (literal.empty())
		return ;
	else if (literal.size() == 1 && !std::isdigit(literal.at(0)))
		type = CHAR;
	else if (!isInt(literal))
		type = INT;
    else if (!isFloat(literal))
		type = FLOAT;
    else if (!isDouble(literal))
		type = DOUBLE;
}
