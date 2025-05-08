/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:29:55 by efinda            #+#    #+#             */
/*   Updated: 2025/05/07 12:29:19 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
    public:
        Ice();
        ~Ice();
        Ice(const Ice &other);
        Ice &operator=(const Ice &);
        Ice    *clone() const;
        void    use(ICharacter &target);
};

#endif