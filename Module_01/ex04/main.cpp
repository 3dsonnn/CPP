/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:10:21 by efinda            #+#    #+#             */
/*   Updated: 2024/12/12 03:12:00 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex04.hpp"

int	main(int ac, char **av)
{
	std::ifstream	file;
	std::ofstream	replace_file;

	check_args(ac, av);
	check_file(file, *(av + 1));
	open_replace_file(replace_file, *(av + 1));
	replace(file, replace_file, *(av + 2), *(av + 3));

	return (0);
}
