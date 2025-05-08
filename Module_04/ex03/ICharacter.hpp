/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:10:10 by efinda            #+#    #+#             */
/*   Updated: 2025/05/07 12:07:15 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>

class   AMateria;

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const   &getName() const = 0;
        virtual void    equip(AMateria* m) = 0;
        virtual void    unequip(int idx) = 0;
        virtual void    use(int idx, ICharacter& target) = 0;
};

#endif