/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:22:50 by efinda            #+#    #+#             */
/*   Updated: 2025/05/31 14:07:18 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error!\nInvalid number of arguments. You need to pass as parameter the literal you want to convert." << std::endl;
        return (1);
    }
    ScalarConverter::convert(static_cast<std::string>(*av + 1));
}
