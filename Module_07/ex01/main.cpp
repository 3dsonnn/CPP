/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:39:17 by efinda            #+#    #+#             */
/*   Updated: 2025/06/09 11:51:56 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void    print(const int &i) { std::cout << i << std::endl; }

void    increment(int &i) { i++; }

template<typename D>
void    decrement(D &i) { i--; }

int main( void )
{
    int arr[3] = {0, 1, 2};

    std::cout << "-----ORIGINAL-----" << std::endl;
    ::iter(arr, sizeof(arr) / sizeof(int), print);
    std::cout << "-----INCREMENTED-----" << std::endl;
    ::iter(arr, sizeof(arr) / sizeof(int), increment);
    ::iter(arr, sizeof(arr) / sizeof(int), print);
    std::cout << "-----DECREMENTED-----" << std::endl;
    ::iter(arr, sizeof(arr) / sizeof(int), decrement<int>);
    ::iter(arr, sizeof(arr) / sizeof(int), print);
    
    return (0);
}
