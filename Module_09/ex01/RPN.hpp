/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:06:46 by efinda            #+#    #+#             */
/*   Updated: 2025/06/23 17:47:03 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>

#define CHARS "0123456789+-/*"

class RPN
{
    private:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        std::stack<int> stack;
        std::string     arg;
        void            _RPN( void );
        bool            check_arg( void );
        int             do_op(int first, int second, char op);
    public:
        RPN(const char *input);
        ~RPN();
};

#endif