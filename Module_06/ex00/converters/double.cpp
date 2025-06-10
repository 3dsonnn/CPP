/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:30:00 by efinda            #+#    #+#             */
/*   Updated: 2025/06/06 15:04:38 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Aux.hpp"

static  bool    for_fun(std::string literal, double d)
{
    float       f;
    std::string arr[] = {"+inf", "-inf", "nan"};

    for (int i = 0; i < 3; i++)
    {
        if (!literal.compare(arr[i]))
        {
            switch(i)
            {
                case 0:
                    d = INFINITY;
                    f = static_cast<float>(d);
                    displayResult(f, d);
                    return (true);
                case 1:
                    d = -INFINITY;
                    f = static_cast<float>(d);
                    displayResult(f, d);
                    return (true);
                case 2:
                    d = std::numeric_limits<double>::quiet_NaN();
                    f = static_cast<float>(d);
                    displayResult(f, d);
                    return (true);
            }
        }
    }
    return (false);
}

void	convertDouble(std::string literal)
{
    double      d;
    int         answer;
    std::string ref(literal);

    if (for_fun(literal, d))
        return ;
    answer = validate_literal(ref, std::string("double"));
    if (answer)
    {
        if (answer == 1)
            displayResult(std::string("impossible"));
        return ;
    }
    std::cout << std::fixed << std::setprecision(6);
    std::istringstream  aux(ref);
    if (!(aux >> d))
        std::cerr << "istringstream failed to convert a string into a double." << std::endl;
    else
        displayResult(d);
}
