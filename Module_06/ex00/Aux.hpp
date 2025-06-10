/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aux.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:31:51 by efinda            #+#    #+#             */
/*   Updated: 2025/06/05 19:25:05 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_HPP
# define AUX_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <limits>
# include <cmath>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
    NONE
}		t_type;

void	detectType(std::string literal, t_type &type);
void	convertChar(std::string literal);
void	convertInt(std::string literal);
void	convertFloat(std::string literal);
void	convertDouble(std::string literal);

void	displayResult(const std::string res);
void	displayResult(char c);
void	displayResult(int i);
void	displayResult(float f);
void	displayResult(double d);
void	displayResult(float f, double d);

int			validate_literal(std::string &literal, std::string id);

#endif