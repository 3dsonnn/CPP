/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:46:03 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 15:46:10 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Cat : public Animal
{
    private:
        Brain   *brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat &other);
        Cat    &operator=(const Cat &other);
        void    makeSound() const;
};

#endif