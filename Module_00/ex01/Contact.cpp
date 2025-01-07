/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:12:28 by efinda            #+#    #+#             */
/*   Updated: 2024/12/08 06:22:57 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	Contact::getstr(char ref) const
{
	if (ref == 'f')
		return (first);
	if (ref == 'l')
		return (last);
	if (ref == 'n')
		return (nick);
	if (ref == 'p')
		return (phone);
	if (ref == 's')
		return (secret);
	return (NULL);
}

int	Contact::getinit(void)
{
	return (init());
}

int	Contact::init(void)
{
	std::cout << "Input the first name" << std::endl;
	std::cin >> first;
	if (check_name(first))
		return (1);
	std::cout << "Input the last name" << std::endl;
	std::cin >> last;
	if (check_name(last))
		return (1);
	std::cout << "Input the nickname" << std::endl;
	std::cin >> nick;
	if (check_name(nick))
		return (1);
	std::cout << "Input the phone number" << std::endl;
	std::cin >> phone;
	if (ft_strnbr(phone.c_str()))
	{
		std::cout << NOPHONE;
		return (1);
	}
	std::cout << "Input the darkest secret" << std::endl;
	std::cin >> secret;
	if (check_name(secret))
		return (1);
	return (0);
}
