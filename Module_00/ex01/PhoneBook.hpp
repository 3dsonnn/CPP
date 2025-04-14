/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:19:21 by efinda            #+#    #+#             */
/*   Updated: 2025/04/12 16:51:47 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

#define INVALID_ARGS "Incorrect! Run the program using only ./phonebook"
#define NONAME "A name cannot contain non alphabetic characters\n"
#define NOPHONE "A phone number cannot contain non numeric characters\n"
#define NOINT "The index you provided is wrong, it's not an integer\n"
#define OFR "The index you provided is out of range (0 - 7)\n"
#define NAV "The index you provided is not available\n"
#define PIPE "|"

class PhoneBook
{
private:
	Contact contacts[8];
	int index;
	void display(void) const;

public:
	PhoneBook(void);
	void save(Contact contact);
	void search(void) const;
};

int ft_strnbr(const char *str);
int check_name(const std::string str);
void print_truncated(std::string const str);
int my_getline(std::string &str);

#endif
