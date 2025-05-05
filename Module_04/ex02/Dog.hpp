/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:45:37 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 16:01:55 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class   Dog: public AAnimal
{
    private:
        Brain   *brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &other);
        Dog    &operator=(const Dog &other);
        void    makeSound() const;
};

#endif