/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 06:46:43 by efinda            #+#    #+#             */
/*   Updated: 2025/06/23 07:41:35 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define DB_PATH "data.csv"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>

class BitcoinExchange
{
    private:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        std::map<std::string, float>  database;
        std::string                 line;
        std::ifstream               file;
        std::ifstream               DB;
        bool            evaluateClosestLowerValue(const std::string key, float &dvalue);
        void            evaluateInputFile( void );
        float           isValidInputLine( void ) const;
        bool            checkInputFile(const char *input);
        bool            createDB( void );
        bool            isCSV( void ) const;
        bool            checkDB( void );
        bool            isValidDate(const std::string date) const;
        int             countChar(const std::string str, char c) const;
    public:
        BitcoinExchange(const char *input);
        ~BitcoinExchange();
};

#endif