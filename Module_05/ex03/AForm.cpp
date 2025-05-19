/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:39:16 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 11:35:32 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//  Orthodox Canonical Form - start
AForm::AForm(): name("Default AForm"), status(false), gradeToSign(150), gradeToExec(150) { std::cout << "AForm default constructor called" << std::endl; }

AForm::~AForm() { std::cout << "AForm destructor called" << std::endl; }

AForm::AForm(const AForm &other): name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
    std::cout << "AForm copy constructor called" << std::endl;
    *this = other;
}

AForm   &AForm::operator=(const AForm &other)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &other)
        this->status = other.status;
    return (*this);
}
//  Orthodox Canonical Form - end

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): name(name), status(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    std::stringstream   itoa;

    std::cout << "AForm constructor called" << std::endl;
    if (gradeToSign < 1)
    {
        itoa << gradeToSign;
        throw   GradeTooHighException("AForm " + name + " cannot be construted with grade to sign " + itoa.str() + " it's too high.");
    }
    if (gradeToSign > 150)
    {
        itoa << gradeToSign;
        throw   GradeTooLowException("AForm " + name + " cannot be construted with grade to sign " + itoa.str() + " it's too low.");
    }
    if (gradeToExec < 1)
    {
        itoa << gradeToExec;
        throw   GradeTooHighException("AForm " + name + " cannot be construted with grade to exec " + itoa.str() + " it's too high.");
    }
    if (gradeToExec > 150)
    {
        itoa << gradeToExec;
        throw   GradeTooLowException("AForm " + name + " cannot be construted with grade to exec " + itoa.str() + " it's too low.");
    }
}

void        AForm::beSigned(const Bureaucrat &bureaucrat)
{
    std::stringstream   itoa;
    std::string         message;

    if (bureaucrat.getGrade() <= gradeToSign)
        status = true;
    else
    {
        itoa << bureaucrat.getGrade();
        message = "Bureaucrat " + bureaucrat.getName() + " couldn't sign the aform " + name + " because it's grade - " + itoa.str() + " is lowest then the required - ";
        itoa.str("");
        itoa.clear();
        itoa << gradeToSign;
        message += itoa.str() + ".";
        throw GradeTooLowException(message);
    }
}

// GETTERS
std::string AForm::getName()   const { return (name); }
bool        AForm::getStatus()    const { return (status); }
int         AForm::getGradeToSign()    const { return (gradeToSign); }
int         AForm::getGradeToExec()    const { return (gradeToExec); }

std::ostream  &operator<<(std::ostream &out, const AForm &aform)
{
    std::string tmp;

    aform.getStatus() ? tmp = " is signed. " : tmp = " is not signed. ";
    out << aform.getName() << tmp << "It requires " << aform.getGradeToSign()
        << " to be signed and " << aform.getGradeToExec() << " to be executed.";
    return (out);
}

// EXCEPTION CLASSES

    // GRADE TOO HIGH
AForm::GradeTooHighException::GradeTooHighException(std::string message): message(message) { }

AForm::GradeTooHighException::~GradeTooHighException() throw() { }

const char  *AForm::GradeTooHighException::what()  const throw() { return (message.c_str()); }
    // GRADE TOO HIGH
    
    // GRADE TOO LOW
AForm::GradeTooLowException::GradeTooLowException(std::string message): message(message) { }

AForm::GradeTooLowException::~GradeTooLowException() throw() { }

const char  *AForm::GradeTooLowException::what()   const throw() { return (message.c_str()); }
    // GRADE TOO LOW