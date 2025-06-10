/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AuxDisplayResult.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:59:47 by efinda            #+#    #+#             */
/*   Updated: 2025/06/07 15:54:10 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aux.hpp"

void	displayResult(const std::string res)
{
    std::cout << "char: " << res << std::endl;
    std::cout << "int: " << res << std::endl;
    std::cout << "float: " << res << std::endl;
    std::cout << "double: " << res << std::endl;
}

void	displayResult(char c)
{
    if (std::isprint(c) && c != ' ')
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	displayResult(int i)
{
    if (i > 32 && i < 127)
        std::cout << "char: " << static_cast<char>(i) << std::endl;
    else if (!(i >= -128 && i <= 127))
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void	displayResult(float f)
{
    if (f > 32 && f < 127 && isprint(static_cast<char>(f)))
        std::cout << "char: " << static_cast<char>(f) << std::endl;
    else if (!(f >= -128 && f <= 127))
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (f < static_cast<float>(std::numeric_limits<int>::min())
        || f > static_cast<float>(std::numeric_limits<int>::max()))
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	displayResult(double d)
{
    if (d > 32 && d < 127 && isprint(static_cast<char>(d)))
        std::cout << "char: " << static_cast<char>(d) << std::endl;
    else if (!(d >= -128 && d <= 127))
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (d < static_cast<double>(std::numeric_limits<int>::min())
        || d > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    if (d < static_cast<double>(std::numeric_limits<float>::min())
        || d > static_cast<double>(std::numeric_limits<float>::max()))
        std::cout << "float: " << "impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
    std::cout << "double: " << d << std::endl;
}

void	displayResult(float f, double d)
{
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << f << 'f' << std::endl;
    std::cout << "double: " << d << std::endl;
}
