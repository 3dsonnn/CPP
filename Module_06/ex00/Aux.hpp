/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aux.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:31:51 by efinda            #+#    #+#             */
/*   Updated: 2025/05/31 15:20:26 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_HPP
# define AUX_HPP

# include <iostream>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
    NONE
}		t_type;

void	detectType(std::string literal, t_type *type);
// char	getChar(std::string);
// int     getInt(std::string);
// float	getChar(std::string);
// double	getChar(std::string);

#endif