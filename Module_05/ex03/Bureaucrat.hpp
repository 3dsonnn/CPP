/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:10:14 by efinda            #+#    #+#             */
/*   Updated: 2025/05/13 13:07:00 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <sstream>
# include "AForm.hpp"

class   AForm;

class Bureaucrat
{
    private:
        const   std::string name;
        int                 grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat   &operator=(const Bureaucrat &other);
        Bureaucrat(std::string name, int grade);
        std::string getName(void)   const;
        int         getGrade(void)  const;
        void        incrementGrade(void);
        void        decrementGrade(void);
        void        signForm(AForm &form)    const;
        void        executeForm(AForm const & form) const;
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif