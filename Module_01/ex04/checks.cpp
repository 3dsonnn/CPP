/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:11:02 by efinda            #+#    #+#             */
/*   Updated: 2024/12/13 15:11:02 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex04.hpp"

void	check_args(const int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: Invalid number of parameter. Read the instructions!" << std::endl;
		exit(1);
	}
	if (!*(*(av + 1)))
	{
		std::cerr << "Error: The filename cannot be an empty string" << std::endl;
		exit(1);
	}
	if (!*(*(av + 2)))
	{
		std::cerr << "Error: The s1 string cannot be an empty string" << std::endl;
		exit(1);
	}
}

void	check_file(std::ifstream &file, char *filename)
{
	file.open(filename);

	if (!file.is_open())
	{
		if (errno == ENOENT)
			std::cerr << "Error: The file " << filename << " doesn't exist" << std::endl;
		else if (errno == EACCES)
			std::cerr << "Error: There's no permission to open the file " << filename << std::endl;
		else
			std::cerr << "Error: An error ocurred when trying to open the file " << filename << std::endl;
		exit(1);
	}
	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
	{
		std::cerr << "Error: The file " << filename << " is empty" << std::endl;
		file.close();
		exit(1);
	}
	file.seekg(0);
}
