/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:06:50 by efinda            #+#    #+#             */
/*   Updated: 2025/06/23 17:45:57 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN &other) { (void)other; }

RPN &RPN::operator=(const RPN &other) { (void)other; return (*this); }

RPN::~RPN() { }

RPN::RPN(const char *arg)
{
    this->arg.assign(arg);
    if (check_arg())
        return ;
    _RPN();
}

void    RPN::_RPN( void )
{
    int i1;
    int i2;
    std::size_t index;

    index = arg.find_first_of(CHARS);
    while (index != std::string::npos)
    {
        if (arg.at(index) >= '0' && arg.at(index) <= '9')
            stack.push(arg.at(index) - '0');
        else
        {
            if (stack.size() < 2)
                { std::cout << "Error: bad argument." << std::endl; return ; }
            i1 = stack.top();
            stack.pop();
            i2 = stack.top();
            stack.pop();
            stack.push(do_op(i2, i1, arg.at(index)));
        }
        index = arg.find_first_of(CHARS, index + 1);
    }
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
    else
        std::cout << "Error: bad argument." << std::endl;
}

int RPN::do_op(int first, int second, char op)
{
    if (op == '+')
        return (first + second);
    if (op == '-')
        return (first - second);
    if (op == '*')
        return (first * second);
    if (op == '/')
    {
        if (!second)
            return (second);
        return (first / second);
    }
    return (0);
}

bool    RPN::check_arg( void )
{
    std::string chars(" 0123456789+-/*");
    bool        toggle = false;

    if (arg.empty())
        return (std::cout << "Error: empty argument." << std::endl, true);
    if (arg.size() < 5)
        return (std::cout << "Error: argument too short." << std::endl, true);
    for (std::size_t i = 0; i < arg.size(); i++)
        if (chars.find_first_of(arg.at(i)) == std::string::npos)
            return (std::cout << "Error: invalid char at position " << i << "." << std::endl, true);
    while (arg.size() && arg.at(0) == ' ')
        arg.erase(0, 1);
    if (arg.empty())
        return (std::cout << "Error: argument full of spaces." << std::endl, true);
    while (arg.at(arg.size() - 1) == ' ')
        arg.erase(arg.size() - 1, 1);
    if (arg.size() < 5 || !(arg.at(0) >= '0' && arg.at(0) <= '9'))
        return (std::cout << "Error: bad argument." << std::endl, true);
    for (std::size_t i = 0; i < arg.size(); i++)
    {
        if (arg.at(i) == ' ')
            toggle = false;
        else
        {
            if (toggle)
                return (std::cout << "Error: bad argument." << std::endl, true);
            toggle = true;
        }
    }
    return (false);
}
