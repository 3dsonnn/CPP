/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:45:37 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 15:44:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class   Dog: public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog &other);
        Dog    &operator=(const Dog &other);
        void    makeSound() const;
};

#endif