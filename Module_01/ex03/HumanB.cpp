/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:25:35 by efinda            #+#    #+#             */
/*   Updated: 2024/12/11 19:25:35 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), arm(nullptr) {}

void	HumanB::setWeapon(Weapon &arm)
{
	this->arm = &arm;
}

void	HumanB::attack(void) const
{
	if (arm)
		std::cout << name << " attacks with their " << arm->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack" << std::endl;
}
