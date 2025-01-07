/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:06:28 by efinda            #+#    #+#             */
/*   Updated: 2024/12/13 16:06:30 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex04.hpp"

void	open_replace_file(std::ofstream &replace_file, char *filename)
{
	std::string	replace_filename;
	
	replace_filename = std::string(filename) + ".replace";
	replace_file.open(replace_filename);
	if (!replace_file.is_open())
	{
		std::cerr << "Error: Failed to open " << replace_filename << std::endl;
		exit(1);
	}
}
