/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:06:18 by efinda            #+#    #+#             */
/*   Updated: 2024/12/13 16:06:19 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex04.hpp"

void	replace(std::ifstream &file, std::ofstream &replace_file, char *s1, char *s2)
{
	size_t		line_pos;
	size_t		tmp_pos;
	std::string	line;
	std::string	tmp;
	
	while (std::getline(file, tmp))
	{
		tmp.push_back('\n');
		line.append(tmp);
	}
	if (line.find(s1) == std::string::npos)
	{
		replace_file << line;
		return ;
	}
	while (42)
	{
		line_pos = line.find(s1);
		if (line_pos == std::string::npos)
			break ;
		tmp = line.substr(0, (line_pos + strlen(s1)));
		line.erase(0, tmp.size());
		tmp_pos = tmp.find(s1);
		tmp.erase(tmp_pos, strlen(s1));
		tmp.insert(tmp_pos, s2);
		replace_file << tmp;
	}
	replace_file << line;
	file.close();
	replace_file.close();
}
