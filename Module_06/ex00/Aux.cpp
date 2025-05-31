/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aux.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:31:33 by efinda            #+#    #+#             */
/*   Updated: 2025/05/31 18:53:25 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aux.hpp"

void	detectType(std::string literal, t_type *type)
{
    if (literal.empty())
    {
        *type = NONE;
        return ;
    }
    if (literal.size() == 1)
    {
        char c = literal.at(0);
        if (c >= 0 && c <= 127)
        {
            *type = CHAR;
            return ;
        }
    }
    if (literal.at(literal.size() - 1) == 'f')
    {
        char c = static_cast<char>(literal.at(0));
        if (c >= static_cast<char>(0) && c <= static_cast<char>(127))
            *type = CHAR;
    }
}
