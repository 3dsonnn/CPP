/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:52:18 by efinda            #+#    #+#             */
/*   Updated: 2025/06/12 19:30:16 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void )
{
    srand(time(NULL));

    std::cout << "---------- SUBJECT TESTS ----------" << std::endl;
    {
        Span    sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl << "---------- 10,000 NUMBERS TEST ----------" << std::endl;
    {
        Span    sp(10000);
        long long int   value;
    
        for (int i = 0; i < 10000; i++)
        {
            value = rand() - (RAND_MAX / 2);
            sp.addNumber(value);
        }

        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

        std::cout << std::endl << "---------- ATTEMPT TO ADD MORE THAN N NUMBERS TEST ----------" << std::endl;
        try { sp.addNumber(value); }
            catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
    }

    std::cout << std::endl << "---------- SHORTEST AND LONGEST SPANS FOR LESS THAN 2 NUMBERS TEST ----------" << std::endl;
    {
        Span    sp(1);

        sp.addNumber(42);

        try { std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; }
            catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
        try { std::cout << "longestSpan: " << sp.longestSpan() << std::endl; }
            catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
    }

    std::cout << std::endl << "---------- LAST BUT NOT LEAST, ADDRANGE TEST ----------" << std::endl;
    {
        int arr[] = {6, 3, 17, 9, 11};
        std::vector<int> vec;

        Span    sp(sizeof(arr) / sizeof(int));
        vec.assign(arr, arr + sizeof(arr) / sizeof(int));

        sp.addRange(vec.begin(), vec.end());

        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    }

    return 0;
}
