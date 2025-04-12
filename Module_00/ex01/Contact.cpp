/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:12:28 by efinda            #+#    #+#             */
/*   Updated: 2025/04/12 16:52:12 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string Contact::getField(char ref) const
{
	if (ref == 'f')
		return (fields[FIRST_NAME]);
	if (ref == 'l')
		return (fields[LAST_NAME]);
	if (ref == 'n')
		return (fields[NICKNAME]);
	if (ref == 'p')
		return (fields[PHONE_NUMBER]);
	if (ref == 's')
		return (fields[DARKEST_SECRET]);
	return (std::string(""));
}

void Contact::setField(char ref, const std::string value)
{
	if (ref == 'f')
		fields[FIRST_NAME] = value;
	if (ref == 'l')
		fields[LAST_NAME] = value;
	if (ref == 'n')
		fields[NICKNAME] = value;
	if (ref == 'p')
		fields[PHONE_NUMBER] = value;
	if (ref == 's')
		fields[DARKEST_SECRET] = value;
}
