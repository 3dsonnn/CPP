/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:10:01 by efinda            #+#    #+#             */
/*   Updated: 2025/05/14 10:44:10 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//  Orthodox Canonical Form - start
Bureaucrat::Bureaucrat(): name("Default Bureaucrat"), grade(150) { std::cout << "Bureaucrat default constructor called" << std::endl; }

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor called" << std::endl; }

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat   &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::stringstream   itoa;

    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        itoa << other.grade;
        if (other.grade < 1)
            throw   GradeTooHighException(other.name + " grade is too high: " + itoa.str() + ".");
        if (other.grade > 150)
            throw   GradeTooLowException(other.name + " grade is too low: " + itoa.str() + ".");
        this->grade = other.grade;
    }
    return (*this);
}
//  Orthodox Canonical Form - end

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::stringstream   itoa;

    std::cout << "Bureaucrat constructor called" << std::endl;
    itoa << grade;
    if (grade < 1)
        throw   GradeTooHighException(name + " grade is too high: " + itoa.str() + ".");
    if (grade > 150)
        throw   GradeTooLowException(name + " grade is too low: " + itoa.str() + ".");
}

void        Bureaucrat::incrementGrade(void)
{
    if (grade - 1 < 1)
        throw   GradeTooHighException(name + " grade cannot be incremented because it's value is already the highest possible.");
    grade--;
}

void        Bureaucrat::decrementGrade(void)
{
    if (grade + 1 > 150)
        throw   GradeTooLowException(name + " grade cannot be decremented because it's value is already the lowest possible.");
    grade++;
}

void        Bureaucrat::signForm(AForm &form)    const
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because "
            << e.what() << std::endl;
    }
}

void        Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << name << " couldn't execute " << form.getName() << " because "
            << e.what() << std::endl;
    }
}

std::string Bureaucrat::getName()   const { return (name); }

int         Bureaucrat::getGrade()  const { return (grade); }

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return (out);
}

// EXCEPTION CLASSES

    // GRADE TOO HIGH
Bureaucrat::GradeTooHighException::GradeTooHighException(std::string message): message(message) { }

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() { }

const char  *Bureaucrat::GradeTooHighException::what()  const throw() { return (message.c_str()); }
    // GRADE TOO HIGH
    
    // GRADE TOO LOW
Bureaucrat::GradeTooLowException::GradeTooLowException(std::string message): message(message) { }

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() { }

const char  *Bureaucrat::GradeTooLowException::what()   const throw() { return (message.c_str()); }
    // GRADE TOO LOW