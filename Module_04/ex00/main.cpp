/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:42:11 by efinda            #+#    #+#             */
/*   Updated: 2025/05/05 12:30:50 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "*****SUBJECT TESTS*****" << std::endl;

    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Type: " << dog->getType() << std::endl;
    std::cout << "Type: " << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();
    animal->makeSound();

    delete  dog;
    delete  cat;
    delete  animal;

    std::cout << std::endl << "*****WRONG CLASSES TESTS*****" << std::endl;

    WrongAnimal *wrong_cat = new WrongCat();

    std::cout << "Type: " << wrong_cat->getType() << std::endl;

    wrong_cat->makeSound();

    delete  wrong_cat;

    return 0;
}
