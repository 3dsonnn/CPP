/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:39:16 by efinda            #+#    #+#             */
/*   Updated: 2025/05/14 10:33:32 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//  Orthodox Canonical Form - start
Form::Form(): name("Default Form"), status(false), gradeToSign(150), gradeToExec(150) { std::cout << "Form default constructor called" << std::endl; }

Form::~Form() { std::cout << "Form destructor called" << std::endl; }

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
    std::cout << "Form copy constructor called" << std::endl;
    *this = other;
}

Form   &Form::operator=(const Form &other)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other)
        this->status = other.status;
    return (*this);
}
//  Orthodox Canonical Form - end

void        Form::beSigned(const Bureaucrat &bureaucrat)
{
    std::stringstream   itoa;
    std::string         message;

    if (bureaucrat.getGrade() <= gradeToSign)
        status = true;
    else
    {
        itoa << bureaucrat.getGrade();
        message = "Bureaucrat " + bureaucrat.getName() + " couldn't sign the form " + name + " because it's grade - " + itoa.str() + " is lowest then the required - ";
        itoa.str("");
        itoa.clear();
        itoa << gradeToSign;
        message += itoa.str() + ".";
        throw GradeTooLowException(message);
    }
}

Form::Form(std::string name, int gradeToSign, int gradeToExec): name(name), status(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    std::stringstream   itoa;

    std::cout << "Form constructor called" << std::endl;
    if (gradeToSign < 1)
    {
        itoa << gradeToSign;
        throw   GradeTooHighException("Form " + name + " cannot be construted with grade to sign " + itoa.str() + " it's too high.");
    }
    if (gradeToSign > 150)
    {
        itoa << gradeToSign;
        throw   GradeTooLowException("Form " + name + " cannot be construted with grade to sign " + itoa.str() + " it's too low.");
    }
    if (gradeToExec < 1)
    {
        itoa << gradeToExec;
        throw   GradeTooHighException("Form " + name + " cannot be construted with grade to exec " + itoa.str() + " it's too high.");
    }
    if (gradeToExec > 150)
    {
        itoa << gradeToExec;
        throw   GradeTooLowException("Form " + name + " cannot be construted with grade to exec " + itoa.str() + " it's too low.");
    }
}

// GETTERS
std::string Form::getName()   const { return (name); }
bool        Form::getStatus()    const { return (status); }
int         Form::getGradeToSign()    const { return (gradeToSign); }
int         Form::getGradeToExec()    const { return (gradeToExec); }

std::ostream  &operator<<(std::ostream &out, const Form &form)
{
    std::string tmp;

    form.getStatus() ? tmp = " is signed. " : tmp = " is not signed. ";
    out << form.getName() << tmp << "It requires " << form.getGradeToSign()
        << " to be signed and " << form.getGradeToExec() << " to be executed.";
    return (out);
}

// EXCEPTION CLASSES

    // GRADE TOO HIGH
Form::GradeTooHighException::GradeTooHighException(std::string message): message(message) { }

Form::GradeTooHighException::~GradeTooHighException() throw() { }

const char  *Form::GradeTooHighException::what()  const throw() { return (message.c_str()); }
    // GRADE TOO HIGH
    
    // GRADE TOO LOW
Form::GradeTooLowException::GradeTooLowException(std::string message): message(message) { }

Form::GradeTooLowException::~GradeTooLowException() throw() { }

const char  *Form::GradeTooLowException::what()   const throw() { return (message.c_str()); }
    // GRADE TOO LOW