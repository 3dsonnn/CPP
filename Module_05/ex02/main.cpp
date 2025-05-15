/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:23:21 by efinda            #+#    #+#             */
/*   Updated: 2025/05/14 15:56:48 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

void    section(std::string title) { std::cout << "\n\033[1;34m=== " << title << " ===\033[0m\n"; }

int	main( void )
{
	section("1. Criação e Impressão");
	{
		Bureaucrat              bob("Bob", 50);
		ShrubberyCreationForm   shrub("home");
		RobotomyRequestForm     robot("android");
		PresidentialPardonForm  pardon("prisoner");

		std::cout << bob << std::endl
                << shrub << std::endl
                << robot << std::endl
                << pardon << std::endl;
	}

	section("2. Execução sem assinatura");
	{
		Bureaucrat              exec("Exec", 1);
		ShrubberyCreationForm   shrub("garden");
		RobotomyRequestForm     robot("bot");
		PresidentialPardonForm  pardon("target");

		try { exec.executeForm(shrub); }
            catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
		try { exec.executeForm(robot); }
            catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
		try { exec.executeForm(pardon); }
            catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	}

	section("3. Assina mas não consegue executar");
	{
		Bureaucrat              lowExec("LowExec", 140);
		ShrubberyCreationForm   shrub("forest");

		lowExec.signForm(shrub);
		try { lowExec.executeForm(shrub); }
		    catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	}

	section("4. Execuções bem-sucedidas");
	{
		Bureaucrat              master("Master", 1);
		ShrubberyCreationForm   shrub("treehouse");
		RobotomyRequestForm     robot("mech");
		PresidentialPardonForm  pardon("criminal");

		master.signForm(shrub);
		master.executeForm(shrub);
		master.signForm(robot);
		master.executeForm(robot);
		master.signForm(pardon);
		master.executeForm(pardon);
	}

	section("5. Aleatoriedade do Robotomy");
	{
		Bureaucrat          exec("BotExec", 1);
		RobotomyRequestForm robot("cyborg");

		exec.signForm(robot);
		for (int i = 0; i < 10; ++i)
		{
			std::cout << "Attempt " << (i + 1) << ": ";
			exec.executeForm(robot);
		}
	}

	section("6. Criação de arquivo Shrubbery");
	{
		Bureaucrat              worker("Worker", 130);
		ShrubberyCreationForm   shrub("backyard");

		worker.signForm(shrub);
		worker.executeForm(shrub);

		std::ifstream   file("backyard_shrubbery");
		if (file.is_open())
			std::cout << "Arquivo criado com sucesso." << std::endl;
		else
			std::cerr << "Falha ao criar arquivo." << std::endl;
	}

	section("7. Mensagem de execução Bureaucrat");
	{
		Bureaucrat          exec("Exec", 1);
		RobotomyRequestForm robot("unitX");

		exec.signForm(robot);
		exec.executeForm(robot);
	}

	section("8. Grau baixo ao assinar");
	{
		Bureaucrat              lowRank("Low", 150);
		ShrubberyCreationForm   shrub("home");

		try { lowRank.signForm(shrub); }
		    catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	}

	section("9. Vários burocratas com formulários");
	{
		Bureaucrat          high("High", 1);
		Bureaucrat          mid("Mid", 70);
		Bureaucrat          low("Low", 140);
		RobotomyRequestForm robot("drone");

		high.signForm(robot);
		high.executeForm(robot);
		try { mid.executeForm(robot); }
		    catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
		try { low.signForm(robot); }
		    catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
	}

	std::cout << "\n\033[1;32mTodos os testes foram executados.\033[0m\n";

	return (0);
}
