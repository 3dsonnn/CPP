/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:39:05 by efinda            #+#    #+#             */
/*   Updated: 2025/06/10 19:26:51 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void    iter(T *addr, size_t len, F ft)
{
    if (!addr || len <= 0)
        return ;
    for (size_t i = 0; i < len; i++)
        ft(addr[i]);
}

#endif
