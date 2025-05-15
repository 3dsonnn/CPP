/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:38:55 by efinda            #+#    #+#             */
/*   Updated: 2025/05/13 12:10:51 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "***** OUT OF BOUNDS TEST *****" << std::endl;
    try { Bureaucrat  txavier("txavier", 151); }
        catch (const Bureaucrat::GradeTooLowException &e) { std::cerr << e.what() << std::endl; }
    try { Bureaucrat  ahamuyel("ahamuyel", 0); }
        catch (const Bureaucrat::GradeTooHighException &e) { std::cerr << e.what() << std::endl; }

    Bureaucrat  efinda("efinda", 42);
    Bureaucrat  jbofengo("jbofengo", 100);

    std::cout << std::endl << "***** INCREMENT TEST *****" << std::endl;
    for (int i = 0; i < 42; i++)
    {
        try
        {
            std::cout << efinda << std::endl;
            efinda.incrementGrade();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl << "***** DECREMENT TEST *****" << std::endl;
    for (int i = 0; i < 51; i++)
    {
        try
        {
            std::cout << jbofengo << std::endl;
            jbofengo.decrementGrade();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return (0);
}
