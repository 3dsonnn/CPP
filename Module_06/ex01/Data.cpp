/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:38:34 by efinda            #+#    #+#             */
/*   Updated: 2025/06/06 15:32:13 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : name(""), age(0) { std::cout << "Data Default Constructor Called" << std::endl; }

Data::~Data() { std::cout << "Data Destructor Called" << std::endl; }

Data::Data(const Data &other)
{
    std::cout << "Data Copy Constructor Called" << std::endl;
    *this = other;
}

Data &Data::operator=(const Data &other)
{
    std::cout << "Data Copy Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        this->age = other.age;
        this->name = other.name;
    }
    return (*this);
}

Data::Data(std::string name, int age) : name(name), age(age) { std::cout << "Data Constructor Called" << std::endl; }