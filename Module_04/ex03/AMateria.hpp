/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:05:55 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 16:35:27 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CPP
# define AMATERIA_CPP

#include <iostream>

class   AMateria
{
    protected:
        [...]
    public:
        AMateria();
        ~AMateria();
        void    AMateria(const AMateria &other);
        AMateria    &operator=(const AMateria &other);
        AMateria(std::string const &type);
        [...]
        std::string const &getType() const;
        virtual AMateria    *clone() const = 0;
        virtual void    use(ICharacter &target);
};

#endif