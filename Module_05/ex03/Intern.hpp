/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:35:53 by efinda            #+#    #+#             */
/*   Updated: 2025/05/15 16:13:36 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class   Intern
{
    private:
        AForm   *ShrubberyCreation(std::string target);
        AForm   *RobotomyRequest(std::string target);
        AForm   *PresidentialPardon(std::string target);
    public:
        Intern();
        ~Intern();
        Intern(const Intern &other);
        Intern   &operator=(const Intern &other);
        AForm   *makeForm(std::string formName, std::string formTarget);
};

#endif