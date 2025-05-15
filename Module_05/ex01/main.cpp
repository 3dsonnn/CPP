/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:52:22 by efinda            #+#    #+#             */
/*   Updated: 2025/05/13 11:27:59 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Test 1: Valid form and bureaucrat
void	testValidCreation( void )
{
	std::cout << "Test 1: Valid Form and Bureaucrat creation\n" << std::endl;
	Bureaucrat	bob("Bob", 50);
	Form		form1("Tax Form", 60, 40);

	std::cout << bob << std::endl;
	std::cout << form1 << std::endl;
}

// Test 2: Grade too high
void	testGradeTooHigh( void )
{
	std::cout << "Test 2: Form with grade too high\n" << std::endl;
	Form	form2("Invalid Form", 0, 50);
	
	std::cout << form2 << std::endl;
}

// Test 3: Grade too low
void	testGradeTooLow( void )
{
	std::cout << "Test 3: Form with grade too low\n" << std::endl;
	Form	form3("Invalid Form", 151, 50);

	std::cout << form3 << std::endl;
}

// Test 4: Successful signing
void	testSuccessfulSigning( void )
{
	std::cout << "Test 4: Successful form signing\n" << std::endl;
	Bureaucrat	alice("Alice", 30);
	Form		form4("Permit Form", 50, 20);

	std::cout << "Before: " << form4 << std::endl;
	alice.signForm(form4);
	std::cout << "After: " << form4 << std::endl;
}

// Test 5: Failed signing
void	testFailedSigning( void )
{
	std::cout << "Test 5: Failed form signing (grade too low)\n" << std::endl;
	Bureaucrat	charlie("Charlie", 60);
	Form		form5("License Form", 50, 30);

	std::cout << "Before: " << form5 << std::endl;
	charlie.signForm(form5);
	std::cout << "After: " << form5 << std::endl;
}

// Test 6: Loop with successful signing
void	testMultipleSigning( void )
{
	std::cout << "Test 6: Loop to test signing multiple forms\n" << std::endl;
	Bureaucrat	dave("Dave", 10);

	for (int i = 1; i <= 3; i++)
	{
		std::string	name = "Form " + std::string(1, 'A' + i - 1);
		Form		form(name, 20 - i * 5, 20);

		std::cout << "Attempting to sign " << name << std::endl;
		dave.signForm(form);
		std::cout << form << std::endl << std::endl;
	}
}

// Test 7: Loop with failed signing
void	testFailedMultipleSigning( void )
{
	std::cout << "Test 7: Loop to test signing with insufficient grade\n" << std::endl;
	Bureaucrat	eve("Eve", 100);

	for (int i = 0; i < 3; i++)
	{
		std::string	name = "Form X" + std::string(1, '0' + i);
		Form		form(name, 50, 50);

		std::cout << "Attempting to sign " << name << std::endl;
		eve.signForm(form);
		std::cout << form << std::endl << std::endl;
	}
}

// Test 8: Edge case with grade 1
void	testEdgeCase( void )
{
	std::cout << "Test 8: Edge case with do-while loop\n" << std::endl;
	Bureaucrat	frank("Frank", 1);
	Form		form6("Critical Form", 1, 1);

	std::cout << "Before: " << form6 << std::endl;
	frank.signForm(form6);
	std::cout << "After: " << form6 << std::endl;
	frank.incrementGrade(); // should throw
}

int	main( void )
{
	void	(*tests[8])() = {
		testValidCreation,
		testGradeTooHigh,
		testGradeTooLow,
		testSuccessfulSigning,
		testFailedSigning,
		testMultipleSigning,
		testFailedMultipleSigning,
		testEdgeCase
	};

	for (int i = 0; i < 8; ++i)
	{
		std::cout << "---------------------------------------------" << std::endl;
		try { tests[i](); }
		    catch ( const std::exception &e) { std::cerr << "Error: " << e.what() << std::endl; }
		std::cout << "---------------------------------------------\n" << std::endl;
	}

	return 0;
}
