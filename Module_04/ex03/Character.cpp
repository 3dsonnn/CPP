/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:09:52 by efinda            #+#    #+#             */
/*   Updated: 2025/05/08 15:58:44 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int     Character::flag = 0;
Floor   *Character::floor = NULL;

//  Orthodox Canonical Form - start
Character::Character()
{
    flag++;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    std::cout << "Character default constructor called" << std::endl;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (inventory[i])
            delete inventory[i];
    flag--;
    if (!flag && floor)
        Character::floor->clean(Character::floor);
}

Character::Character(const Character &other)
{
    flag++;
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    *this = other;
}

Character   &Character::operator=(const Character &other)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
                delete this->inventory[i];
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return (*this);
}
//  Orthodox Canonical Form - end

Character::Character(std::string name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    flag++;
}

std::string const   &Character::getName() const { return (name); }

void    Character::equip(AMateria *m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
        if (inventory[i] == m)
            return ;
    if (floor->sameAddr(floor, m))
        floor->removeNode(floor, m);
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            break ;
        }
    }
}

void    Character::unequip(int idx)
{
    if (idx > -1 && idx < 4)
    {
        if (inventory[idx])
        {
            if (!floor)
                floor = floor->newNode(inventory[idx]);
            else if (!floor->sameAddr(floor, inventory[idx]))
                floor->addBack(floor, floor->newNode(inventory[idx]));
            inventory[idx] = NULL;
        }
    }
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx > -1 && idx < 4)
        if (inventory[idx])
            inventory[idx]->use(target);
}
