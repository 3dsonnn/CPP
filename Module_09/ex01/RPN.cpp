/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:06:50 by efinda            #+#    #+#             */
/*   Updated: 2025/06/27 17:20:08 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN &other) { (void)other; }

RPN &RPN::operator=(const RPN &other) { (void)other; return (*this); }

RPN::~RPN() { }

RPN::RPN(const char *arg): arg(arg) { _RPN(); }

int RPN::do_op(int first, int second, char op)
{
    if (op == '+')
        return (first + second);
    if (op == '-')
        return (first - second);
    if (op == '*')
        return (first * second);
    if (op == '/')
        return (first / second);
    return (0);
}

bool    RPN::isNBR(std::string str)
{
    bool        sig = false;

    if (str.empty())
        return (false);
    if (str.at(0) == '+' || str.at(0) == '-')
    {
        if (str.size() == 1)
            return (false);
        if (str.at(0) == '-')
            sig = true;
        str.erase(0, 1);
    }
    for (std::size_t i = 0; i < str.size(); i++)
        if (!std::isdigit(str.at(i)))
            return (false);
    if (str.at(0) == '0')
    {
        std::size_t zero = str.find_first_not_of('0', 0);
        if (zero == std::string::npos)
            return (true);
        str.erase(0, zero);
    }
    return (true);
}

void    RPN::_RPN( void )
{
    std::string chars(" 0123456789+-/*");
    std::string nbr;
    int         i1, i2;
    std::size_t start = 0, end;

    if (arg.empty())
        { std::cout << "Error: empty argument." << std::endl; return ; }
    for (std::size_t i = 0; i < arg.size(); i++)
        if (chars.find_first_of(arg.at(i)) == std::string::npos)
            { std::cout << "Error: invalid char at position " << i << "." << std::endl; return ; }
    while (arg.size() && arg.at(0) == ' ')
        arg.erase(0, 1);
    if (arg.empty())
        { std::cout << "Error: argument full of spaces." << std::endl; return ; }
    while (arg.at(arg.size() - 1) == ' ')
        arg.erase(arg.size() - 1, 1);
    end = arg.find_first_of(' ');
    if (end == std::string::npos)
    {
        if (isNBR(arg))
            { std::cout << arg << std::endl; return ; }
        { std::cout << "Error: bad argument." << std::endl; return ; }
    }
    while (-42)
    {
        nbr = arg.substr(start, end - start);
        if (!isNBR(nbr) && nbr.size() != 1
            && nbr.compare("+") && nbr.compare("-") && nbr.compare("*") && nbr.compare("/"))
            { std::cout << "Error: bad argument." << std::endl; return ; }
        if (!nbr.compare("+") || !nbr.compare("-") || !nbr.compare("*") || !nbr.compare("/"))
        {
            if (stack.size() < 2)
                { std::cout << "Error: bad argument." << std::endl; return ; }
            i1 = stack.top();
            stack.pop();
            i2 = stack.top();
            stack.pop();
            stack.push(do_op(i2, i1, nbr.at(0)));
        }
        else
        {
            std::istringstream  iss(nbr);
            if (!(iss >> i1))
                { std::cerr << "Error: failed to convert string to integer." << std::endl; return ; }
            stack.push(i1);
        }
        start = arg.find_first_not_of(' ', end);
        if (start == std::string::npos)
            break ;
        end = arg.find_first_of(' ', start);
        if (end == std::string::npos)
            end = arg.size();
    }
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
    else
        std::cout << "Error: bad argument." << std::endl;
}
