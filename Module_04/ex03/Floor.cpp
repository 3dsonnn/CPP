/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:28:08 by efinda            #+#    #+#             */
/*   Updated: 2025/05/08 15:47:11 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

void    Floor::addBack(Floor *&head, Floor *newNode)
{
    Floor *tmp;

    if (!head)
        head = newNode;
    else
    {
        tmp = head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = newNode;
    }
}

Floor   *Floor::newNode(AMateria *addr)
{
    Floor   *res;
    
    res = new Floor;
    res->ptr = addr;
    res->next = NULL;
    return (res);
}

int     Floor::sameAddr(Floor *&head, AMateria *addr)
{
    Floor   *tmp;

    tmp = head;
    while (tmp)
    {
        if (tmp->ptr == addr)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    Floor::removeNode(Floor *&head, AMateria *addr)
{
    Floor   *cur;
    Floor   *prev;

    prev = NULL;
    cur = head;
    while (cur)
    {
        if (cur->ptr == addr)
        {
            if (prev)
                prev->next = cur->next;
            else
                head = cur->next;
            delete cur;
            return ;
        }
        prev = cur;
        cur = cur->next;
    }
}

void    Floor::clean(Floor *&head)
{
    Floor   *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        delete tmp->ptr;
        delete tmp;
    }
}
