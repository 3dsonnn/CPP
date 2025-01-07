/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:19:15 by efinda            #+#    #+#             */
/*   Updated: 2024/12/08 06:12:55 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define CONTACT_HPP

# include "PhoneBook.hpp"

class	Contact
{
	private:
		std::string	first;
		std::string	last;
		std::string	nick;
		std::string	phone;
		std::string	secret;
		int		init(void);
	public:
		std::string	getstr(char ref) const;
		int		getinit(void);
};

#endif
