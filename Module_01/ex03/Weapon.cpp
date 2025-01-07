/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:26:52 by efinda            #+#    #+#             */
/*   Updated: 2024/12/11 19:26:53 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type) {}

const	std::string	&Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string newtype)
{
	type = newtype;
}
