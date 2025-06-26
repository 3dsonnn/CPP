/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:54:43 by efinda            #+#    #+#             */
/*   Updated: 2025/06/26 19:01:29 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <sys/time.h>

# define DIGITS "0123456789"

class   PmergeMe
{
    private:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe    &operator=(const PmergeMe &other);
        template <int INTEGER> struct Int2Type { enum {TYPE = INTEGER}; };
        char                **av;
        std::vector<int>    tmp;
        std::vector<int>    vct;
        std::deque<int>     dqe;
        std::size_t         times[2];
        void                FordJohnson(std::vector<int> &vect);
        void                FordJohnson(std::deque<int> &dqe);
        std::deque<int>     generateJacobsthal(int n, Int2Type<0>);
        std::vector<int>    generateJacobsthal(int n, Int2Type<1>);
        void                showTimes( void ) const;
        void                getTime(struct timeval start, struct timeval end, std::size_t &time);
        bool                check_av( void );
    public:
        PmergeMe(char **av);
        ~PmergeMe();
};

#endif