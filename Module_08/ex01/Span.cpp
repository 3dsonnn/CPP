/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:52:36 by efinda            #+#    #+#             */
/*   Updated: 2025/06/12 18:01:57 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): N(0) { }

Span::~Span() { }

Span::Span(const Span &other): N(other.N) { *this = other; }

Span    &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        buffer = other.buffer;
    }
    return (*this);
}

Span::Span(unsigned int N): N(N) { }

void    Span::addNumber(int nbr)
{
    if (buffer.size() == N)
        throw std::exception();
    buffer.push_back(nbr);
}

long long int  Span::longestSpan( void ) const
{
    if (N < 2)
        throw std::exception();
    std::vector<int>::const_iterator minIt = std::min_element(buffer.begin(), buffer.end());
    std::vector<int>::const_iterator maxIt = std::max_element(buffer.begin(), buffer.end());
    return (static_cast<long long int>(*maxIt) - *minIt);
}

long long int  Span::shortestSpan( void )
{
    if (N < 2)
        throw std::exception();
    long long int res = longestSpan();
    long long int size = buffer.size();
    std::stable_sort(buffer.begin(), buffer.end());
    for (long long int i = 1; i < size; i++)
        buffer.at(i) - buffer.at(i - 1) < res ? res = buffer.at(i) - buffer.at(i - 1) : res = res;
    return (res);
}
