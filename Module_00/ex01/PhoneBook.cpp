/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:01:29 by efinda            #+#    #+#             */
/*   Updated: 2025/04/15 19:11:14 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::save(Contact contact)
{
	if (index == 8)
		index = 0;
	contacts[index] = contact;
	index++;
}

void PhoneBook::display(void) const
{
	int i = -1;

	std::cout << std::right << std::setw(10) << "Index"
			  << PIPE << std::setw(10) << "First Name"
			  << PIPE << std::setw(10) << "Last Name"
			  << PIPE << std::setw(10) << "Nickname" << std::endl;
	while (++i < 8)
	{
		if (contacts[i].getField('f') == "")
			return ;
		std::cout << std::setw(10) << i << PIPE;
		print_truncated(contacts[i].getField('f'));
		std::cout << PIPE;
		print_truncated(contacts[i].getField('l'));
		std::cout << PIPE;
		print_truncated(contacts[i].getField('n'));
		std::cout << std::endl;
	}
}

void PhoneBook::search(void) const
{
	std::string str;
	int nbr;

	if (index == 0)
	{
		std::cout << "The phonebook is empty" << std::endl;
		return;
	}
	display();
	std::cout << "Enter the index of the contact to be displayed" << std::endl;
	if (my_getline(str))
		exit(1);
	if (ft_strnbr(str.c_str()))
	{
		std::cerr << NOINT;
		return;
	}
	nbr = atoi(str.c_str());
	if (nbr < 0 && nbr > 7)
	{
		std::cerr << OFR;
		return;
	}
	if (nbr >= index)
	{
		std::cerr << NAV;
		return;
	}
	std::cout << contacts[nbr].getField('f') << std::endl
			  << contacts[nbr].getField('l') << std::endl
			  << contacts[nbr].getField('n') << std::endl
			  << contacts[nbr].getField('p') << std::endl
			  << contacts[nbr].getField('s') << std::endl;
}
