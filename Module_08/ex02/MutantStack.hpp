/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:58:52 by efinda            #+#    #+#             */
/*   Updated: 2025/06/13 15:08:13 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
# define MUTANTSTACK

# include <stack>
#include <iostream>
# include <algorithm>

template < class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
        MutantStack() { }
        ~MutantStack() { }
        MutantStack(const MutantStack &other): std::stack<T, Container>(other) { }
        MutantStack &operator=(const MutantStack &other)
        {
            if (this != &other)
                std::stack<T, Container>::operator=(other);
            return (*this);
        }

        typedef typename Container::iterator                iterator;
        typedef typename Container::const_iterator          const_iterator;
        typedef typename Container::reverse_iterator        reverse_iterator;
        typedef typename Container::const_reverse_iterator  const_reverse_iterator;
        
        iterator begin( void ) { return (this->c.begin()); }
        iterator end( void ) { return (this->c.end()); }

        const_iterator begin( void ) const { return (this->c.begin()); }
        const_iterator end( void ) const { return (this->c.end()); }

        reverse_iterator rbegin( void ) { return (this->c.rbegin()); }
        reverse_iterator rend( void ) { return (this->c.rend()); }

        const_reverse_iterator rbegin( void ) const { return (this->c.rbegin()); }
        const_reverse_iterator rend( void ) const { return (this->c.rend()); }
};

#endif