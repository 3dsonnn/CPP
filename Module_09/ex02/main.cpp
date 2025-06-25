/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:54:50 by efinda            #+#    #+#             */
/*   Updated: 2025/06/24 14:21:19 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Error: a positive integer sequence is required as an argument." << std::endl, 1);
    PmergeMe    pushSwap(av + 1);
}
