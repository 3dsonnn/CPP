/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:42:11 by efinda            #+#    #+#             */
/*   Updated: 2025/05/08 17:21:02 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    AAnimal  *animal[42];

    for (int i = 0; i < 42; i++)
    {
        if (i < 21)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
    }

    for (int i = 0; i < 42; i++)
    {
        std::cout << "Type: " << animal[i]->getType() << std::endl;
        animal[i]->makeSound();
    }

    for (int i = 0; i < 42; i++)
        delete  animal[i];

    return 0;
}
