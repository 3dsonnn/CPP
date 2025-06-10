/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:16:03 by efinda            #+#    #+#             */
/*   Updated: 2025/06/05 16:56:42 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { std::cout << "Default Constructor Called" << std::endl; }

ScalarConverter::~ScalarConverter() { std::cout << "Destructor Called" << std::endl; }

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; std::cout << "Copy Constructor Called" << std::endl; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; std::cout << "Copy Assignment Operator Called" << std::endl; return (*this); }

void    ScalarConverter::convert(std::string literal)
{
    t_type  type = NONE;
    void    (*functions[])(std::string) = {convertChar, convertInt, convertFloat, convertDouble};

    detectType(literal, type);
    if (type == NONE)
        displayResult(std::string("impossible"));
    else
    {
        for (int i = 0; i < 4; i++)
            if (type == i)
                functions[i](literal);
    }
}
