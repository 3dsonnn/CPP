/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:39:05 by efinda            #+#    #+#             */
/*   Updated: 2025/06/09 11:34:22 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename U>
void    iter(T *addr, size_t len, U (*ft)(T &element))
{
    if (!addr || len <= 0 || !ft)
        return ;
    for (size_t i = 0; i < len; i++)
        ft(addr[i]);
}

template<typename T, typename U>
void    iter(T *addr, size_t len, U (*ft)(const T &element))
{
    if (!addr || len <= 0 || !ft)
        return ;
    for (size_t i = 0; i < len; i++)
        ft(addr[i]);
}

#endif
