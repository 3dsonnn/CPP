/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:57:04 by efinda            #+#    #+#             */
/*   Updated: 2025/06/10 09:12:23 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <exception>

template <typename T>
Array<T>::Array(): buffer(NULL), length(0) { }

template <typename T>
Array<T>::~Array()
{
    if (buffer)
        delete[] buffer;
}

template <typename T>
Array<T>::Array(unsigned int n) : buffer(new T[n]()), length(n) { }

template <typename T>
Array<T>::Array(const Array &other): buffer(NULL), length(0) { *this = other; }

template <typename T>
Array<T>    &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        unsigned int    size = other.size();
        if (buffer)
            delete[] buffer;
        if (!size)
            buffer = NULL;
        else
        {
            buffer = new T[size]();
            for (size_t i = 0; i < size; i++)
                buffer[i] = other.buffer[i];
        }
        length = size;
    }
    return (*this);
}

template <typename T>
T   &Array<T>::operator[](unsigned int index)
{
    if (index >= length)
        throw std::exception();
    return (buffer[index]);
}

template <typename T>
const T   &Array<T>::operator[](unsigned int index) const
{
    if (index >= length)
        throw std::exception();
    return (buffer[index]);
}

template <typename T>
unsigned int    Array<T>::size( void ) const { return (length); }

#endif