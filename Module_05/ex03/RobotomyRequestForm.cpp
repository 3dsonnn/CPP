/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:32:32 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 11:37:41 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

//  Orthodox Canonical Form - start
RobotomyRequestForm::RobotomyRequestForm(): AForm() { std::cout << "RobotomyRequestForm default constructor called" << std::endl; }

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm destructor called" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other) { std::cout << "RobotomyRequestForm copy constructor called" << std::endl; }

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}
//  Orthodox Canonical Form - end

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target + "_RobotomyRequestForm", 72, 45), target(target) { std::cout << "RobotomyRequestForm constructor called" << std::endl; }

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    static  bool    flag = true;

    if (!this->getStatus())
        throw   std::runtime_error("Bureaucrat " + executor.getName() + " couldn't execute the Form " + this->getName() + " because it's not signed.");
    if (executor.getGrade() > 45)
        throw   std::runtime_error("Bureaucrat " + executor.getName() + " couldn't execute the Form " + this->getName() + " because it's grade isn't high enough.");
    std::cout << "BZZZZZTTT... DRRRRRRRR... VRRRRRRRRR..." << std::endl;
    if (flag)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy of " << target << " failed." << std::endl;
    flag = !flag;
}
