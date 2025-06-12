/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:21:41 by efinda            #+#    #+#             */
/*   Updated: 2025/06/12 12:15:55 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include <iostream>
# include <vector>
# include <list>
# include <set>

template <class C, unsigned int amount>
void    fillIntegerContainer(C &container)
{
    for (unsigned int i = 0; i < amount; i++)
    {
        long value = -2147483648 + rand() % (4294967295 + 1);
        if (rand() % 2)
            value *= -1;
        container.insert(container.end(), value);
        std::cout << value << " | ";
    }
    std::cout << std::endl << std::endl;
}

void    promptResult(int value, bool result)
{
    if (result)
        std::cout << "The value " << value << " was found inside the container" << std::endl;
    else
        std::cout << "The value " << value << " wasn't found inside the container" << std::endl;
}

template <class C, unsigned int times>
void    randomSearch(C &container)
{
    for (unsigned int i = 0; i < times; i++)
    {
        long value = -2147483648 + rand() % (4294967295 + 1);
        if (rand() % 2)
            value *= -1;
        promptResult(value, easyfind(container, 2));
    }
    std::cout << std::endl << std::endl;
}

template <class C, unsigned int times>
void    findValues(C &container)
{
    typename C::const_iterator it = container.begin();
    for (unsigned int i = 0; i < times && it != container.end(); i++)
    {
        promptResult(*it, easyfind(container, *it));
        it++;
    }
    std::cout << std::endl << std::endl;
}

int main( void )
{
    srand(time(NULL));

    std::vector<int>    vector;
    std::list<int>      list;
    std::set<int>       set;

    std::cout << std::endl << "---------------------- VECTOR ----------------------" << std::endl << std::endl;
    fillIntegerContainer<std::vector<int>, 42>(vector);
    randomSearch<std::vector<int>, 24>(vector);
    findValues<std::vector<int>, 24>(vector);
    
    std::cout << std::endl << "---------------------- LIST ----------------------" << std::endl << std::endl;
    fillIntegerContainer<std::list<int>, 42>(list);
    randomSearch<std::list<int>, 24>(list);
    findValues<std::list<int>, 24>(list);

    std::cout << std::endl << "---------------------- SET ----------------------" << std::endl << std::endl;
    fillIntegerContainer<std::set<int>, 42>(set);
    randomSearch<std::set<int>, 24>(set);
    findValues<std::set<int>, 24>(set);

    return (0);
}
