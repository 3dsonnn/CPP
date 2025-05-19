/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:39:41 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 11:24:08 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <sstream>
# include "Bureaucrat.hpp"

class   Bureaucrat;

class   Form
{
    private:
        const std::string   name;
        bool                status;
        const int           gradeToSign;
        const int           gradeToExec;
    public:
        Form();
        ~Form();
        Form(const Form &other);
        Form    &operator=(const Form &other);
        Form(std::string name, int gradeToSign, int gradeToExec);
        std::string getName()   const;
        bool        getStatus()    const;
        int         getGradeToSign()    const;
        int         getGradeToExec()    const;
        void        beSigned(const Bureaucrat &bureaucrat);
        class   GradeTooHighException: public std::exception
        {
            private:
                std::string message;
            public:
                GradeTooHighException(std::string message);
                virtual ~GradeTooHighException()    throw();
                virtual const char  *what() const throw();
        };
        class   GradeTooLowException: public std::exception
        {
            private:
                std::string message;
            public:
                GradeTooLowException(std::string message);
                virtual ~GradeTooLowException() throw();
                virtual const char  *what() const throw();
        };
};

std::ostream  &operator<<(std::ostream &out, const Form &form);

#endif