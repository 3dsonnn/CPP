/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:29:36 by efinda            #+#    #+#             */
/*   Updated: 2025/06/05 20:14:13 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Aux.hpp"

static  bool    for_science(std::string literal, float f)
{
    double      d;
    std::string arr[] = {"+inff", "-inff", "nanf"};

    for (int i = 0; i < 3; i++)
    {
        if (!literal.compare(arr[i]))
        {
            switch(i)
            {
                case 0:
                    f = INFINITY;
                    d = static_cast<double>(f);
                    displayResult(f, d);
                    return (true);
                case 1:
                    f = -INFINITY;
                    d = static_cast<double>(f);
                    displayResult(f, d);
                    return (true);
                case 2:
                    f = std::numeric_limits<float>::quiet_NaN();
                    d = static_cast<double>(f);
                    displayResult(f, d);
                    return (true);
            }
        }
    }
    return (false);
}

void	convertFloat(std::string literal)
{
    float       f;
    int         answer;
    std::string ref(literal);

    if (for_science(literal, f))
        return ;
    answer = validate_literal(ref, std::string("float"));
    if (answer)
    {
        if (answer == 1)
            displayResult(std::string("impossible"));
        return ;
    }
    std::istringstream  aux(ref);
    if (!(aux >> f))
        std::cerr << "istringstream failed to convert a string into a float." << std::endl;
    else
        displayResult(f);
}
