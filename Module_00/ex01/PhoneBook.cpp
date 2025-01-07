/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:01:29 by efinda            #+#    #+#             */
/*   Updated: 2024/12/10 01:01:30 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): counter(0), oldest(0) {}

void	PhoneBook::save_contact(Contact contact)
{
	if (counter < 8)
	{
		contacts[counter] = contact;
		counter++;
	}
	else
	{
		contacts[oldest] = contact;
		if (oldest == 7)
			oldest = -1;
		oldest++;
	}
}

void	PhoneBook::display_contacts(void) const
{
	int	i;

	i = -1;
	std::cout << std::right << std::setw(10) << "Index"
		<< PIPE << std::setw(10) << "First Name"
		<< PIPE << std::setw(10) << "Last Name"
		<< PIPE << std::setw(10) << "Nickname" << std::endl;
	while (++i < counter)
	{
		std::cout << std::setw(10) << i << PIPE;
		print_truncated(contacts[i].getstr('f'));
		std::cout << PIPE;
		print_truncated(contacts[i].getstr('l'));
		std::cout << PIPE;
		print_truncated(contacts[i].getstr('n'));
		std::cout << std::endl;
	}
}

void	PhoneBook::search(void) const
{
	std::string	str;
	int		i;

	if (counter == 0)
	{
		std::cout << "The phonebook is empty" << std::endl;
		return ;
	}
	display_contacts();
	std::cout << "Enter the index of the contact to be displayed" << std::endl;
	std::getline(std::cin, str);
	if (ft_strnbr(str.c_str()))
	{
		std::cerr << NOINT;
		return ;
	}
	i = atoi(str.c_str());
	if (i < 0 && i > 7)
	{
		std::cerr << OFR;
		return ;
	}
	if (i >= counter)
	{
		std::cerr << NAV;
		return ;
	}
	std::cout << contacts[i].getstr('f') << std::endl
		<< contacts[i].getstr('l') << std::endl
		<< contacts[i].getstr('n') << std::endl
		<< contacts[i].getstr('p') << std::endl
		<< contacts[i].getstr('s') << std::endl;
}
