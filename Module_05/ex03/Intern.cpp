/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:35:46 by efinda            #+#    #+#             */
/*   Updated: 2025/05/15 17:12:40 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//  Orthodox Canonical Form - start
Intern::Intern() { std::cout << "Intern default constructor called" << std::endl; }

Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern   &Intern::operator=(const Intern &other)
{
    std::cout << "Intern copy assignment operator called" << std::endl;
    if (this != &other)
    {
        
    }
    return (*this);
}
//  Orthodox Canonical Form - end

AForm   *Intern::makeForm(std::string formName, std::string formTarget)
{
    std::string     names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    typedef AForm   *(Intern::*InternPtr)(std::string target);
    InternPtr       functions[] = {&Intern::ShrubberyCreation, &Intern::RobotomyRequest, &Intern::PresidentialPardon};

    try
    {
        for (int i = 0; i < 3; i++)
        {
            if (!formName.compare(names[i]))
            {
                AForm   *res = (this->*functions[i])(formTarget);
                std::cout << "Intern creates " << formName << std::endl;
                return (res);
            }
        }
        throw   std::runtime_error("The provided form name doesn't exist");
    }
    catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
    return (NULL);
}

AForm   *Intern::ShrubberyCreation(std::string target) { return (new ShrubberyCreationForm(target)); }

AForm   *Intern::RobotomyRequest(std::string target) { return (new RobotomyRequestForm(target)); }

AForm   *Intern::PresidentialPardon(std::string target) { return (new PresidentialPardonForm(target)); }
