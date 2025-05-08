/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:27:18 by efinda            #+#    #+#             */
/*   Updated: 2025/05/08 15:58:55 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

#include <iostream>
#include "AMateria.hpp"

struct Floor
{
    AMateria        *ptr;
    Floor   *next;
    Floor   *newNode(AMateria *addr);
    void    addBack(Floor *&head, Floor *newNode);
    int     sameAddr(Floor *&head, AMateria *addr);
    void    removeNode(Floor *&head, AMateria *addr);
    void    clean(Floor *&head);
};

#endif