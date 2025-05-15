/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:35:51 by efinda            #+#    #+#             */
/*   Updated: 2025/05/14 15:58:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//  Orthodox Canonical Form - start
ShrubberyCreationForm::ShrubberyCreationForm(): AForm() { std::cout << "ShrubberyCreationForm default constructor called" << std::endl; }

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "ShrubberyCreationForm destructor called" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other) { std::cout << "ShrubberyCreationForm copy constructor called" << std::endl; }

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}
//  Orthodox Canonical Form - end

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target + "_ShrubberyCreationForm", 145, 137), target(target) { std::cout << "ShrubberyCreationForm constructor called" << std::endl; }

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::ofstream   file;

    try
    {
        if (!this->getStatus())
            throw   std::runtime_error("Bureaucrat " + executor.getName() + " couldn't execute the Form " + this->getName() + " because it's not signed.");
        if (executor.getGrade() > 137)
            throw   std::runtime_error("Bureaucrat " + executor.getName() + " couldn't execute the Form " + this->getName() + " because it's grade isn't high enough.");
        std::string filename = target + "_shrubbery";
        file.open(filename.c_str());
        if (!file.is_open())
            throw   std::runtime_error("Failed to open the file " + target + "_shrubbery.");
        for (int i = 0; i < 3; i++)
        {
            file << "         *\n"
                    "        ***\n"
                    "       *****\n"
                    "      *******\n"
                    "     *********\n"
                    "    ***********\n"
                    "   *************\n"
                    "  ***************\n"
                    " *****************\n"
                    "        |||\n"
                    "        |||\n"
                    "        |||\n\n";
        }
        file.close();
    }
    catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
    
}
