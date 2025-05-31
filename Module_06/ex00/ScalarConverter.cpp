/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:16:03 by efinda            #+#    #+#             */
/*   Updated: 2025/05/31 14:25:50 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { std::cout << "Default Constructor Called" << std::endl; }

ScalarConverter::~ScalarConverter() { std::cout << "Destructor Called" << std::endl; }

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; std::cout << "Copy Constructor Called" << std::endl; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; std::cout << "Copy Assignment Operator Called" << std::endl; return (*this); }

void    ScalarConverter::convert(std::string literal)
{
    std::cout << "char: " << std::endl;
    std::cout << "int: " << std::endl;
    std::cout << "float: " << std::endl;
    std::cout << "double: " << std::endl;
}
