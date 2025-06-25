/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:54:46 by efinda            #+#    #+#             */
/*   Updated: 2025/06/25 12:29:00 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }

PmergeMe    &PmergeMe::operator=(const PmergeMe &other) { (void)other; return (*this); }

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(char **av): av(av)
{
    if (check_av())
        return ;
    for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); it++)
        std::cout << *it << (it + 1 == vct.end() ? '\n' : ' ');
    FordJohnson(vct);
    for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); it++)
        std::cout << *it << (it + 1 == vct.end() ? '\n' : ' ');
}

std::vector<int>    PmergeMe::generateJacobsthal(int n)
{
    std::vector<int>    jacobsthal;
    int                 next;
    int                 i = 4;
    int                 sum = 4;

    if (n <= 0)
        return (jacobsthal);
    jacobsthal.push_back(1);    // J_2 = 1
    if (n == 1)
        return (jacobsthal);
    jacobsthal.push_back(3);    // J_3 = 3
    if (n <= 3)
        return (jacobsthal);
    while (sum < n)
    {
        next = jacobsthal[i - 2] + 2 * jacobsthal[i - 3];
        jacobsthal.push_back(next);
        sum += next;
        i++;
    }
    return (jacobsthal);
}

void    PmergeMe::FordJohnson(std::vector<int> &vect)
{
    std::vector<int>    main, pending, indices, jacobsthal;

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
    int covered = 0;
    jacobsthal = generateJacobsthal(pending.size());
    for (std::vector<int>::size_type j = 0; j < jacobsthal.size() && covered < static_cast<int>(pending.size()); j++)
    {
        int group_size = jacobsthal[j];
        int end = covered + group_size;
        if (end > static_cast<int>(pending.size()))
            end = pending.size();
        for (int k = end - 1; k >= covered && k < static_cast<int>(pending.size()); k--)
            indices.push_back(k);
        covered = end;
    }
    while (covered < static_cast<int>(pending.size()))
    {
        indices.push_back(covered);
        covered++;
    }
    for (std::vector<int>::size_type j = 0; j < indices.size(); j++)
    {
        std::vector<int>::iterator  it = std::upper_bound(main.begin(), main.end(), pending[indices[j]]);
        main.insert(it, pending[indices[j]]);
    }
    vect = main;
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
                if (vct.size())
                {
                    if (std::find(vct.begin(), vct.end(), value) != vct.end())
                        return (std::cerr << "Error: the sequence can't contain duplicate elements {" << i << "}" << std::endl, true);
                    if (sorted && vct.back() > value)
                        sorted = false;
                }
                vct.push_back(value);
            }
            else
                return (std::cerr << "Error: bad argument {" << i << "}" << std::endl, true);
            space = str.find_first_not_of(' ', dgt[1] + 1);
        }
    }
    if (vct.size() == 1)
        return (std::cerr << "A sequence of elements is required." << std::endl, true);
    if (sorted)
        return (std::cerr << "The sequence is already sorted." << std::endl, true);
    lst.assign(vct.begin(), vct.end());
    return (false);
}
