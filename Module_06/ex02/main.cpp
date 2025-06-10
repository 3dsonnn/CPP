/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:50:42 by efinda            #+#    #+#             */
/*   Updated: 2025/06/06 17:32:59 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>

Base    *generate( void )
{
    int     i;
    Base    *res;

    i = rand() % 3;
    if (!i)
        res = new A;
    else if (i == 1)
        res = new B;
    else
        res = new C;
    return (res);
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (const std::exception &e) { (void)e; }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (const std::exception &e) { (void)e; }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (const std::exception &e) { (void)e; }
}

int main( void )
{
    Base    *basePtr;
    srand(time(NULL));

    for (int i = 0; i < 9; i++)
    {
        basePtr = generate();
        Base    &baseRef = *basePtr;

        std::cout << "*** Identify Pointer ***" << std::endl;
        identify(basePtr);

        std::cout << "*** Identify Reference ***" << std::endl;
        identify(baseRef);

        delete basePtr;
        std::cout << std::endl << std::endl;
    }

    std::cout << "*** EDGE CASES ***" << std::endl;

    Base    base;
    Base    &baseRef = base;

    std::cout << "*** Identify Pointer ***" << std::endl;
    identify(&base);

    std::cout << "*** Identify Reference ***" << std::endl;
    identify(baseRef);

    return (0);
}
