/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:23:21 by efinda            #+#    #+#             */
/*   Updated: 2025/05/15 17:15:52 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

void	runTest(const std::string &testName, Intern& intern, const std::string &formName, const std::string &target)
{
	std::cout << "\n==== " << testName << " ====\n" << std::endl;
	try
	{
		AForm	*form;

		form = intern.makeForm(formName, target);
		if (form)
		{
			std::cout << "Success: Intern creates '" << form->getName() << "'" << std::endl;
			std::cout << *form << std::endl;
			delete form;
		}
		else
			std::cerr << "Failed: Intern didn't create '" << formName << "'" << std::endl;
	}
		catch (const std::exception &e) { std::cerr << "Error: " << e.what() << std::endl; }
}

int	main( void )
{
	Intern	intern;

	runTest("Test 1: ShrubberyCreationForm", intern, "shrubbery creation", "garden");
	runTest("Test 2: RobotomyRequestForm", intern, "robotomy request", "Bender");
	runTest("Test 3: PresidentialPardonForm", intern, "presidential pardon", "fugitive");
	runTest("Test 4: Invalid Form Name", intern, "invalid form", "target");

	std::cout << "\n==== Test 5: Loop - Multiple Valid Forms ====\n";
	
	std::string	validForms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::string	targets[3]    = {"park", "cyborg", "traitor"};

	for (int i = 0; i < 3; ++i)
		runTest("Looped Form Test " + std::string(1, (char)(i + 48)), intern, validForms[i], targets[i]);

	std::cout << "\n==== Test 6: Mixed Valid and Invalid Forms (While) ====\n";
	
	std::string	mixedForms[3] = {"shrubbery creation", "invalid form", "robotomy request"};
	std::string	mixedTargets[3] = {"forest", "unknown", "android"};

	int	i = -1;
	while (++i < 3)
		runTest("Mixed While Test" + std::string(1, (char)(i + 48)), intern, mixedForms[i], mixedTargets[i]);

	runTest("Test 7: Simulation (PresidentialPardonForm)", intern, "presidential pardon", "president");
	runTest("Test 8: Case Sensitivity", intern, "SHRUBBERY CREATION", "backyard");
	runTest("Test 9: Empty Form and Target", intern, "", "");

	std::cout << "\n==== Test 10: Bureaucrat Integration ====\n";
	
	try
	{
		Bureaucrat	alice("Alice", 5);
		AForm		*form;

		form = intern.makeForm("presidential pardon", "vip");
		if (form)
		{
			std::cout << "Intern creates " << form->getName() << std::endl;
			alice.signForm(*form);
			alice.executeForm(*form);
			std::cout << *form << std::endl;
			delete form;
		}
	}
		catch (const std::exception &e) { std::cerr << "Error: " << e.what() << std::endl; }

	return (0);
}
