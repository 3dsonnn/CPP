/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:29:53 by efinda            #+#    #+#             */
/*   Updated: 2025/04/12 16:51:56 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int add(Contact &contact)
{
	std::string tmp;

	// FIRST NAME
	std::cout << "Input the first name" << std::endl;
	if (my_getline(tmp))
		exit(1);
	if (check_name(tmp))
		return (1);
	contact.setField('f', tmp);

	// LAST NAME
	std::cout << "Input the last name" << std::endl;
	if (my_getline(tmp))
		exit(1);
	if (check_name(tmp))
		return (1);
	contact.setField('l', tmp);

	// NICKNAME NAME
	std::cout << "Input the nickname" << std::endl;
	if (my_getline(tmp))
		exit(1);
	if (check_name(tmp))
		return (1);
	contact.setField('n', tmp);

	// PHONE NUMBER
	std::cout << "Input the phone number" << std::endl;
	if (my_getline(tmp))
		exit(1);
	if (ft_strnbr(tmp.c_str()))
	{
		if (tmp.empty())
			return (std::cout << EMPTY, 1);
		else
			return (std::cout << NOPHONE, 1);
	}
	contact.setField('p', tmp);

	// DARKEST SECRET
	std::cout << "Input the darkest secret" << std::endl;
	if (my_getline(tmp))
		exit(1);
	contact.setField('s', tmp);
	return (0);
}

int main(int ac, char **av)
{
	PhoneBook phone;
	Contact contact;
	std::string input;
	(void)av;

	if (ac != 1)
		return (std::cerr << INVALID_ARGS << std::endl, 1);
	while (-42)
	{
		std::cout << PROMPT << std::endl;
		if (my_getline(input))
			return (1);
		if (!input.compare("ADD"))
		{
			if (add(contact))
				continue;
			phone.save(contact);
		}
		else if (!input.compare("SEARCH"))
			phone.search();
		else if (!input.compare("EXIT"))
			break;
	}
	return (0);
}
