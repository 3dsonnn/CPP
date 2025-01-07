/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:02:50 by efinda            #+#    #+#             */
/*   Updated: 2024/12/10 18:20:46 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout << "Invalid! Run using only ./brain" << std::endl;
		return (1);
	}
	
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << std::setw(40) << "The memory address of the string is " << &string << std::endl;
	std::cout << std::setw(40) << "The memory address held by stringPTR is " << stringPTR << std::endl;
	std::cout << std::setw(40) << "The memory address held by stringREF is " << &stringREF << std::endl;
	std::cout << std::setw(40) << "The value of the string is " << string << std::endl;
	std::cout << std::setw(40) << "The value pointed to by stringPTR is " << *stringPTR << std::endl;
	std::cout << std::setw(40) << "The value pointed to by stringREF is " << stringREF << std::endl;
	
	return (0);
}
