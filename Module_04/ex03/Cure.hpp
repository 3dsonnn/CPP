/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:30:43 by efinda            #+#    #+#             */
/*   Updated: 2025/05/07 12:29:39 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(const Cure &other);
        Cure    &operator=(const Cure &);
        Cure    *clone() const;
        void    use(ICharacter &target);
};

#endif