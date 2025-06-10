/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:28:41 by efinda            #+#    #+#             */
/*   Updated: 2025/06/05 20:15:14 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Aux.hpp"

static  std::string    prepare_int_literal(std::string literal)
{
    std::string res;
    size_t         i;

    i = (literal.at(0) == '+' || literal.at(0) == '-') ? 1 : 0;
    if (literal.at(0) == '-')
        res.push_back(literal.at(0));
    while (i < literal.size() && literal.at(i) == '0')
        i++;
    if (i == literal.size())
        return (std::string("0"));
    while (i < literal.size())
    {
        res.push_back(literal.at(i));
        i++;
    }
    return (res);
}

static  bool    validate_literal(std::string &literal)
{
    std::string tmp(prepare_int_literal(literal));

    if (literal != tmp)
        literal = tmp;
    if ((literal.at(0) == '-' && literal.size() > 11)
        || (literal.at(0) != '-' && literal.size() > 10))
        return (true);
    if (literal.at(0) != '-' && literal.size() == 10
        && literal.compare("2147483647") > 0)
        return (true);
    else if (literal.at(0) == '-' && literal.size() == 11
        && literal.compare("-2147483648") > 0)
        return (true);
    return (false);
}

void	convertInt(std::string literal)
{
    int         i;
    std::string ref(literal);

    if (validate_literal(ref))
        displayResult(std::string("impossible"));
    else
    {
        std::istringstream  aux(ref);
        if (!(aux >> i))
            std::cerr << "istringstream failed to convert a string into an integer." << std::endl;
        else
            displayResult(i);
    }
}
