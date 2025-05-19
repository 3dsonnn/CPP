/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:39:41 by efinda            #+#    #+#             */
/*   Updated: 2025/05/19 11:31:06 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include <sstream>
# include "Bureaucrat.hpp"

class   Bureaucrat;

class   AForm
{
    private:
        const std::string   name;
        bool                status;
        const int           gradeToSign;
        const int           gradeToExec;
    public:
        AForm();
        virtual ~AForm();
        AForm(const AForm &other);
        AForm    &operator=(const AForm &other);
        AForm(std::string name, int gradeToSign, int gradeToExec);
        std::string getName()   const;
        bool        getStatus()    const;
        int         getGradeToSign()    const;
        int         getGradeToExec()    const;
        void        beSigned(const Bureaucrat &bureaucrat);
        virtual     void    execute(Bureaucrat const &executor) const = 0;
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

std::ostream  &operator<<(std::ostream &out, const AForm &aform);

#endif