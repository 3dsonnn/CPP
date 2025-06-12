/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:52:27 by efinda            #+#    #+#             */
/*   Updated: 2025/06/12 18:00:26 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Span
{
    private:
        Span();
        unsigned int        N;
        std::vector<int>    buffer;
    public:
        ~Span();
        Span &operator=(const Span &other);
        Span(const Span &other);
        Span(unsigned int N);
        void    addNumber(int nbr);
        long long int   shortestSpan( void );
        long long int   longestSpan( void ) const;
        template <class ITERATOR>
        void    addRange(ITERATOR first, ITERATOR last)
        {
            for (ITERATOR i = first; i != last; i++)
                addNumber(static_cast<int>(*i));
        }
};

#endif