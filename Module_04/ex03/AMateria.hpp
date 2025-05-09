/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:05:55 by efinda            #+#    #+#             */
/*   Updated: 2025/05/08 12:29:46 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class   AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        virtual ~AMateria();
        AMateria(const AMateria &);
        AMateria    &operator=(const AMateria &);
        AMateria(std::string const &type);
        std::string const &getType() const;
        virtual AMateria    *clone() const = 0;
        virtual void    use(ICharacter &);
};

#endif