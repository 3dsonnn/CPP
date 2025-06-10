/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:00:37 by efinda            #+#    #+#             */
/*   Updated: 2025/06/05 20:12:28 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Aux.hpp"

static  bool    check_limits(std::string str, std::string limit, char id)
{
    std::string sub;

    if (str.find('.', 0) > limit.find('.', 0))
        return (true);
    if (str.find('.', 0) == limit.find('.', 0))
    {
        if ((id == '+' && str.compare(0, str.find('.', 0), limit, 0, limit.find('.', 0)) > 0)
            || (id == '-' && str.compare(0, str.find('.', 0), limit, 0, limit.find('.', 0)) > 0))
            return (true);
        if (!str.compare(0, str.find('.', 0), limit, 0, limit.find('.', 0)))
        {
            sub = str.substr(str.find('.', 0) + 1, str.size() - (str.find('.', 0) + 1));
            if (sub != std::string(sub.size(), '0'))
                return (true);
        }
    }
    return (false);
}

std::string prepare_literal(std::string literal)
{
    std::string res;

    if (literal.at(literal.size() - 1) == 'f')
        literal.erase(literal.size() - 1, 1);
    size_t  i = (literal.at(0) == '+' || literal.at(0) == '-') ? 1 : 0;
    if (literal.at(0) == '-')
        res.push_back(literal.at(0));
    while (i < literal.size() && literal.at(i) == '0')
        i++;
    if (literal.at(i) == '.')
        res.push_back('0');
    for (size_t j = i; j < literal.size(); j++)
        res.push_back(literal.at(j));
    i = res.size() - 1;
    while (i > 0 && res.at(i) == '0')
        i--;
    if (res.size() - 1 != i)
        res.erase(i + 1, (res.size() - 1) - i);
    if (res.at(res.size() - 1) == '.')
        res.push_back('0');
    return (res);
}

static  int get_limit(std::string &str, long double value, std::string id)
{
    std::stringstream   itoa;
    double              d;
    float               f;
    bool                fail = false;

    itoa << std::fixed << std::setprecision(6);
    if (id.at(0) == 'f')
    {
        f = static_cast<float>(value);
        if (!(itoa << f))
            fail = true;
    }
    else
    {
        d = static_cast<double>(value);
        if (!(itoa << d))
            fail = true;
    }
    if (fail)
    {
        std::cerr << "stringstream failed to convert a " << id << " into a string." << std::endl;
        return (-42);
    }
    str = itoa.str();
    return (0);
}

int validate_literal(std::string &literal, std::string id)
{
    std::string         str_max, str_min;

    if (id.at(0) == 'f')
    {
        if (get_limit(str_max, std::numeric_limits<float>::max(), id)
            || get_limit(str_min, -std::numeric_limits<float>::max(), id))
            return (-42);
    }
    else
    {
        if (get_limit(str_max, std::numeric_limits<double>::max(), id)
            || get_limit(str_min, -std::numeric_limits<double>::max(), id))
            return (-42);
    }
    std::string         tmp(prepare_literal(literal));

    if (literal != tmp)
        literal = tmp;
    if (literal.at(0) == '-' && check_limits(literal, str_min, '-'))
        return (true);
    else if (literal.at(0) != '-' && check_limits(literal, str_max, '+'))
        return (true);
    return (false);
}
