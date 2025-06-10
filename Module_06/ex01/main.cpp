/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:44:10 by efinda            #+#    #+#             */
/*   Updated: 2025/06/06 15:45:54 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main( void )
{
    Data    data("efinda", 42);

    std::cout << std::string(10, '*') << std::endl;

    uintptr_t   serialize = Serializer::serialize(&data);
    Data        *deserialize = Serializer::deserialize(serialize);

    std::cout << "The data object instanciated is stored at address: " << &data << std::endl;
    std::cout << "serialize gave us: " << serialize << std::endl;
    std::cout << "deserialize gave us: " << deserialize << std::endl;
    
    deserialize == &data ? std::cout << "Worked!" : std::cout << "Failed!";
    
    std::cout << std::endl << std::string(10, '*') << std::endl;
    return (0);
}