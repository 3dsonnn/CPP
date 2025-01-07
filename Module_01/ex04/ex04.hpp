/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:40:24 by efinda            #+#    #+#             */
/*   Updated: 2024/12/12 10:40:25 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX04_HPP
# define EX04_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

void	replace(std::ifstream &file, std::ofstream &replace_file, char *s1, char *s2);
void	open_replace_file(std::ofstream &replace_file, char *filename);
void	check_file(std::ifstream &file, char *filename);
void	check_args(int ac, char **av);

#endif
