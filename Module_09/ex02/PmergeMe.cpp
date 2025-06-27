/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:54:46 by efinda            #+#    #+#             */
/*   Updated: 2025/06/27 15:57:14 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }

PmergeMe    &PmergeMe::operator=(const PmergeMe &other) { (void)other; return (*this); }

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(char **av): av(av)
{
    struct timeval  start, end;

    if (check_av())
        return ;
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
        std::cout << *it << (it + 1 == tmp.end() ? '\n' : ' ');
    {
        if (gettimeofday(&start, NULL)) { std::cerr << "Failed to get the time" << std::endl; return ; }
        dqe.assign(tmp.begin(), tmp.end());
        FordJohnson(dqe);
        if (gettimeofday(&end, NULL)) { std::cerr << "Failed to get the time" << std::endl; return ; }
        getTime(start, end, times[0]);
    }
    {
        if (gettimeofday(&start, NULL)) { std::cerr << "Failed to get the time" << std::endl; return ; }
        vct.assign(tmp.begin(), tmp.end());
        FordJohnson(vct);
        if (gettimeofday(&end, NULL)) { std::cerr << "Failed to get the time" << std::endl; return ; }
        getTime(start, end, times[1]);
    }
    std::cout << "After: ";
    for (std::deque<int>::iterator it = dqe.begin(); it != dqe.end(); it++)
        std::cout << *it << (it + 1 == dqe.end() ? '\n' : ' ');
    showTimes();
}

void    PmergeMe::FordJohnson(std::vector<int> &vect)
{
    std::vector<int>    main, pending;

    for (std::size_t i = 0; i < vect.size() - 1; i += 2)
    {
        if (vect.at(i) > vect.at(i + 1))
        {
            main.push_back(vect.at(i));
            pending.push_back(vect.at(i + 1));
        }
        else
        {
            main.push_back(vect.at(i + 1));
            pending.push_back(vect.at(i));
        }
    }
    if (vect.size() % 2)
        pending.push_back(vect.back());
    if (main.size() > 1)
        FordJohnson(main);
    std::size_t         end, last_index = 0;
    std::vector<int>    indices, jacobsthal;
    jacobsthal = generateJacobsthal(pending.size(), Int2Type<1>());
    for (std::size_t round = 0; round < jacobsthal.size() && last_index < pending.size(); round++)
    {
        end = last_index + jacobsthal[round];
        if (end > pending.size())
            end = pending.size();
        for (std::size_t index = end - 1; index >= last_index && index < pending.size(); index--)
            indices.push_back(index);
        last_index = end;
    }
    for (std::size_t aux = last_index; aux < pending.size(); aux++)
        indices.push_back(aux);
    for (std::vector<int>::size_type j = 0; j < indices.size(); j++)
    {
        std::vector<int>::iterator  it = std::upper_bound(main.begin(), main.end(), pending[indices[j]]);
        main.insert(it, pending[indices[j]]);
    }
    vect = main;
}

void    PmergeMe::FordJohnson(std::deque<int> &dqe)
{
    std::deque<int>    main, pending;

    for (std::size_t i = 0; i < dqe.size() - 1; i += 2)
    {
        if (dqe.at(i) > dqe.at(i + 1))
        {
            main.push_back(dqe.at(i));
            pending.push_back(dqe.at(i + 1));
        }
        else
        {
            main.push_back(dqe.at(i + 1));
            pending.push_back(dqe.at(i));
        }
    }
    if (dqe.size() % 2)
        pending.push_back(dqe.back());
    if (main.size() > 1)
        FordJohnson(main);
    std::size_t         end, last_index = 0;
    std::deque<int>     indices, jacobsthal;
    jacobsthal = generateJacobsthal(pending.size(), Int2Type<0>());
    for (std::size_t round = 0; round < jacobsthal.size() && last_index < pending.size(); round++)
    {
        end = last_index + jacobsthal[round];
        if (end > pending.size())
            end = pending.size();
        for (std::size_t index = end - 1; index >= last_index && index < pending.size(); index--)
            indices.push_back(index);
        last_index = end;
    }
    for (std::size_t aux = last_index; aux < pending.size(); aux++)
        indices.push_back(aux);
    for (std::deque<int>::size_type j = 0; j < indices.size(); j++)
    {
        std::deque<int>::iterator  it = std::upper_bound(main.begin(), main.end(), pending[indices[j]]);
        main.insert(it, pending[indices[j]]);
    }
    dqe = main;
}

std::deque<int> PmergeMe::generateJacobsthal(int n, Int2Type<0>)
{
    std::deque<int> jacobsthal;
    int                 next;

    if (n <= 0)
        return (jacobsthal);
    jacobsthal.push_back(1);
    if (n < 3)
        return (jacobsthal);
    jacobsthal.push_back(3);
    if (n < 5)
        return (jacobsthal);
    while (-42)
    {
        next = jacobsthal.at(jacobsthal.size() - 1) + 2 * jacobsthal.at(jacobsthal.size() - 2);
        if (next <= n)
            jacobsthal.push_back(next);
        else
            break ;
    }
    return (jacobsthal);
}

std::vector<int>    PmergeMe::generateJacobsthal(int n, Int2Type<1>)
{
    std::vector<int>    jacobsthal;
    int                 next;

    if (n <= 0)
        return (jacobsthal);
    jacobsthal.push_back(1);
    if (n < 3)
        return (jacobsthal);
    jacobsthal.push_back(3);
    if (n < 5)
        return (jacobsthal);
    while (-42)
    {
        next = jacobsthal.at(jacobsthal.size() - 1) + 2 * jacobsthal.at(jacobsthal.size() - 2);
        if (next <= n)
            jacobsthal.push_back(next);
        else
            break ;
    }
    return (jacobsthal);
}

void    PmergeMe::showTimes( void ) const
{
    std::cout << "Time to process a range of " << dqe.size() << " elements with std::deque<int> : " << times[0] << " microseconds." << std::endl;
    std::cout << "Time to process a range of " << vct.size() << " elements with std::vector<int> : " << times[1] << " microseconds." << std::endl;
}

void    PmergeMe::getTime(struct timeval start, struct timeval end, std::size_t &time)
{
    if (start.tv_sec == end.tv_sec)
        time = end.tv_usec - start.tv_usec;
    else
        time = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
}

bool    PmergeMe::check_av( void )
{
    char                c;
    bool                sorted = true;
    std::size_t         dgt[2];
    std::size_t         space;
    std::size_t         i = -1;
    std::string         str;
    std::string         nbr;

    while (av[++i])
    {
        str.assign(av[i]);
        if (str.empty())
            return (std::cerr << "Error: empty argument {" << i << "}" << std::endl, true);
        for (std::size_t i = 0; i < str.size(); i++)
        {
            c = str.at(i);
            if (!std::isdigit(c) && c != '+' && c != ' ')
                return (std::cerr << "Error: invalid char at argument {" << i << "}" << std::endl, true);
        }
        space = str.find_first_not_of(' ');
        if (space == std::string::npos)
            return (std::cerr << "Error: argument full of spaces {" << i << "}" << std::endl, true);
        while (space != std::string::npos)
        {
            c = str.at(space);
            if (c == '+' && (space == str.size() - 1 || !std::isdigit(str.at(space + 1))))
                return (std::cerr << "Error: bad argument: + must be followed by a digit {" << i << "}" << std::endl, true);
            (c == '+') ? dgt[0] = (space + 1) : dgt[0] = space;
            dgt[1] = str.find_first_not_of(DIGITS, dgt[0]);
            (dgt[1] == std::string::npos) ? dgt[1] = str.size() - 1 : dgt[1] = dgt[1];
            if (str.at(dgt[1]) == ' ' || dgt[1] == str.size() - 1)
            {
                if (!(dgt[1] - dgt[0]))
                    nbr.assign(str.substr(dgt[0], 1));
                else
                    nbr.assign(str.substr(dgt[0], dgt[1] - dgt[0] + 1));
                if (nbr.at(0) == '0')
                {
                    std::size_t tmp = nbr.find_first_not_of('0');
                    if (tmp == std::string::npos)
                        nbr.assign("0");
                    else
                        nbr.erase(0, tmp);
                }
                if (nbr.size() > 10 || (nbr.size() == 10 && nbr.compare("2147483647") > 0))
                    return (std::cerr << "Error: bad argument: greater than max integer {" << i << "}" << std::endl, true);
                std::istringstream  iss(nbr);
                int                 value = -1;
                if (!(iss >> value))
                    return (std::cerr << "Error: failed to convert string to integer {" << i << "}" << std::endl, true);
                if (!value)
                    return (std::cerr << "Error: not positive integer {" << i << "}" << std::endl, true);
                if (tmp.size())
                {
                    if (std::find(tmp.begin(), tmp.end(), value) != tmp.end())
                        return (std::cerr << "Error: the sequence can't contain duplicate elements {" << i << "}" << std::endl, true);
                    if (sorted && tmp.back() > value)
                        sorted = false;
                }
                tmp.push_back(value);
            }
            else
                return (std::cerr << "Error: bad argument {" << i << "}" << std::endl, true);
            space = str.find_first_not_of(' ', dgt[1] + 1);
        }
    }
    if (tmp.size() == 1)
        return (std::cerr << "Error: a sequence of elements is required." << std::endl, true);
    if (sorted)
        return (std::cerr << "Error: the sequence is already sorted." << std::endl, true);
    return (false);
}
