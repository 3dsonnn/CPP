/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:19:21 by efinda            #+#    #+#             */
/*   Updated: 2024/12/08 05:23:37 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstring>
# include <limits>
# include <iomanip>
# include "Contact.hpp"

# define NONAME "A name cannot contain non alphabetic characters\n"
# define NOPHONE "A phone number cannot contain non numeric characters\n"
# define NOINT "The index you provided is wrong, it's not an integer\n"
# define OFR "The index you provided is out of range (0 - 7)\n"
# define NAV "The index you provided is not available\n"
# define PIPE "|"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int	counter;
		int	oldest;
		void	display_contacts(void) const;
	public:
		PhoneBook(void);
		void	save_contact(Contact contact);
		void	search(void) const;
};

int	ft_strnbr(const char *str);
int	check_name(const std::string str);
void	print_truncated(std::string const str);

#endif

