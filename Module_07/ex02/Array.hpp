/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:55:58 by efinda            #+#    #+#             */
/*   Updated: 2025/06/09 15:48:38 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T               *buffer;
        unsigned int    length;
    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array           &operator=(const Array &other);
        const T         &operator[](unsigned int index) const;
        T               &operator[](unsigned int index);
        unsigned int    size( void ) const;
};

#include "Array.tpp"

#endif 