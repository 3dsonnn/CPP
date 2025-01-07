/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:29:53 by efinda            #+#    #+#             */
/*   Updated: 2024/12/08 06:24:51 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int ac, char **av)
{
	PhoneBook	my_phone;
	std::string	input;
	(void)		av;
	
	if (ac != 1)
	{
		std::cerr << "Incorrect! Run the program using only ./phonebook" << std::endl;
		return (1);
	}
	while (-42)
	{
		std::cout << "Enter one of the tree commands (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, input);
		if (strcmp(input.c_str(), "ADD") == 0)
		{
			Contact	contact;
			if (contact.getinit())
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue ;
			}
			my_phone.save_contact(contact);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if  (strcmp(input.c_str(), "SEARCH") == 0)
			my_phone.search();
		else if (strcmp(input.c_str(), "EXIT") == 0)
			break ;
	}
	return (0);
}
