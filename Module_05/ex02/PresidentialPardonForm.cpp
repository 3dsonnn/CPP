/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:57:38 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 11:33:37 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

//  Orthodox Canonical Form - start
PresidentialPardonForm::PresidentialPardonForm(): AForm() { std::cout << "PresidentialPardonForm default constructor called" << std::endl; }

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "PresidentialPardonForm destructor called" << std::endl; }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other) { std::cout << "PresidentialPardonForm copy constructor called" << std::endl; }

PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}
//  Orthodox Canonical Form - end

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target + "_PresidentialPardonForm", 25, 5), target(target) { std::cout << "PresidentialPardonForm constructor called" << std::endl; }

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getStatus())
        throw   std::runtime_error("Bureaucrat " + executor.getName() + " couldn't execute the Form " + this->getName() + " because it's not signed.");
    if (executor.getGrade() > 5)
        throw   std::runtime_error("Bureaucrat " + executor.getName() + " couldn't execute the Form " + this->getName() + " because it's grade isn't high enough.");
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
