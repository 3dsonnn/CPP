/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:10:10 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 20:20:20 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ICHARACTER_HPP
# define ICHARACTER_HPP

class ICharacter
{
    public:
        ICharacter();
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif