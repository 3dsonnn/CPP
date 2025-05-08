/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:13:26 by efinda            #+#    #+#             */
/*   Updated: 2025/05/08 17:38:06 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Floor.hpp"

class Character: public ICharacter
{
    private:
        std::string     name;
        AMateria        *inventory[4];
        void            init_inventory();
        static  int     flag;
        static  Floor   *floor;
    public:
        Character();
        ~Character();
        Character(const Character &other);
        Character   &operator=(const Character &other);
        Character(std::string name);
        std::string const   &getName() const;
        void    equip(AMateria *m);
        void    unequip(int idx);
        void    use(int idx, ICharacter &target);
};

#endif