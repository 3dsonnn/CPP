/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:54:43 by efinda            #+#    #+#             */
/*   Updated: 2025/06/25 12:20:59 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <cstring>
# include <utility>
# include <iterator>

# define DIGITS "0123456789"

class   PmergeMe
{
    private:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe    &operator=(const PmergeMe &other);
        template <int I> struct Int2Type { enum { value = I }; };
        std::vector<int>    vct;
        std::list<int>      lst;
        char                **av;
        std::vector<int>    generateJacobsthal(int n);
        void                FordJohnson(std::vector<int> &vect);
        bool                check_av( void );
    public:
        PmergeMe(char **av);
        ~PmergeMe();
};

#endif