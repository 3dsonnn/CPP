/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:56:41 by efinda            #+#    #+#             */
/*   Updated: 2025/06/10 17:16:58 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void    swap(T &a, T &b)
{
    T   tmp = a;

    a = b;
    b = tmp;
}

template<typename T>
T   min(T a, T b)
{
    if (a == b)
        return b;
    return a < b ? a : b;
}

template<typename T>
T   max(T a, T b)
{
    if (a == b)
        return b;
    return a > b ? a : b;
}

#endif