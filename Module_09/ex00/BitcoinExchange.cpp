/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 08:44:14 by efinda            #+#    #+#             */
/*   Updated: 2025/06/26 16:38:35 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { (void)other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) { (void)other; return (*this); }

BitcoinExchange::BitcoinExchange(const char *input)
{
    if (checkDB()) return ;
    if (checkInputFile(input)) return ;
    if (createDB()) return ;
    evaluateInputFile();
}

float   BitcoinExchange::isValidInputLine( void ) const
{
    std::istringstream  iss;
    std::string         nbr;
    float               res = 0.0f;

    if (line.empty())
        return (std::cerr << "Error: empty line." << std::endl, -1.0f);
    if (line.length() < 14)
        return (std::cerr << "Error: bad input => " << line << std::endl, -1.0f);
    if (isValidDate(line.substr(0, 10)) || line.substr(10, 3) != " | ")
        return (std::cerr << "Error: bad input => " << line << std::endl, -1.0f);
    nbr.assign(line, 13, line.size() - 13);
    if (nbr.empty())
        return (std::cerr << "Error: bad input => " << line << std::endl, -1.0f);
    if (((nbr.at(0) == '+' || nbr.at(0) == '-') && (nbr.size() == 1 || !std::isdigit(nbr.at(1))))
        || countChar(line, '.') > 1 || nbr.at(0) == '.' || nbr.at(nbr.size() - 1) == '.')
        return (std::cerr << "Error: bad input => " << line << std::endl, -1.0f);
    for (std::size_t j = 0; j < nbr.size(); j++)
    {
        if (!j && (nbr.at(j) == '+' || nbr.at(j) == '-'))
            continue ;
        if (!std::isdigit(nbr.at(j)) && nbr.at(j) != '.')
            return (std::cerr << "Error: bad input => " << line << std::endl, -1.0f);
    }
    if (nbr.at(0) == '-')
        return (std::cerr << "Error: not a positive number." << std::endl, -1.0f);
    if (nbr.at(0) == '+')
        nbr.erase(0, 1);
    iss.str(nbr);
    if (iss >> res)
    {
        if (res > 1000)
            return (std::cerr << "Error: too large a number." << std::endl, -1.0f);
        return (res);
    }
    else
        return (std::cerr << "Error: failed to convert string to float." << std::endl, -1.0f);
}

bool    BitcoinExchange::evaluateClosestLowerValue(const std::string key, float &dvalue)
{
    std::map<std::string, float>::iterator itupper = database.upper_bound(key);

    if (itupper == database.begin())
        return (std::cerr << "Error: no lower date available." << std::endl, true);
    itupper--;
    dvalue = itupper->second;
    return (false);
}

void    BitcoinExchange::evaluateInputFile( void )
{
    std::string         key;
    float               dvalue;
    float               ivalue;

    while (std::getline(file, line))
    {
        ivalue = isValidInputLine();
        if (ivalue == -1.0f)
            continue ;
        key = line.substr(0, 10);
        try { dvalue = database.at(key); }
            catch(const std::out_of_range &oor) {
                if (evaluateClosestLowerValue(key, dvalue))
                    continue ;
            }
        std::cerr << key << " => " << ivalue << " = " << (ivalue * dvalue) << std::endl;
    }
}

bool    BitcoinExchange::checkInputFile(const char *input)
{
    file.open(input);
    if (!(file.is_open()))
        return (std::cerr << "Error in input file: failed to open." << std::endl, true);
    if (file.peek() == std::ifstream::traits_type::eof())
        return (std::cerr << "Error in input file: empty." << std::endl, true);
    std::getline(file, line);
    if (line.compare("date | value"))
        return (std::cerr << "Error in input file: incorrect format definition." << std::endl, true);
    if (!std::getline(file, line))
        return (std::cerr << "Error in input file: not providing any date nor values." << std::endl, true);
    file.clear();
    file.seekg(sizeof("date | value"), file.beg);
    return (false);
}

bool    BitcoinExchange::createDB( void )
{
    std::istringstream  iss;
    float               value;

    while (std::getline(DB, line))
    {
        iss.clear();
        iss.str(line.substr(11, line.size() - 11));
        if (!(iss >> value))
            return (std::cerr << "Error in database file: Failed to convert string to float." << std::endl, true);
        database.insert(std::pair<std::string, float>(line.substr(0, 10), value));
    }
    if (database.size() != 1612)
        return (std::cerr << "Error in database file: Incomplete number of elements." << std::endl, true);
    return (false);
}

bool    BitcoinExchange::isCSV( void ) const
{
    std::string nbr;

    if (line.empty())
        return (std::cerr << "Error in database file: empty line." << std::endl, true);
    if (line.length() < 12)
        return (std::cerr << "Error in database file: line too short." << std::endl, true);
    if (isValidDate(line.substr(0, 10)) || line.at(10) != ',')
        return (std::cerr << "Error in database file: bad input => " << line << std::endl, true);
    nbr.assign(line, 11, line.size() - 11);
    if (nbr.empty() || countChar(line, '.') > 1 || nbr.at(0) == '.' || nbr.at(nbr.size() - 1) == '.')
        return (std::cerr << "Error in database file: bad input => " << line << std::endl, true);
    for (std::size_t i = 0; i < nbr.size(); i++)
        if (!std::isdigit(nbr.at(i)) && nbr.at(i) != '.')
            return (std::cerr << "Error in database file: bad input => " << line << std::endl, true);
    return (false);
}

bool    BitcoinExchange::checkDB( void )
{
    DB.open(DB_PATH);
    if (!(DB.is_open()))
        return (std::cerr << "Error in database file: failed to open." << std::endl, true);
    if (DB.peek() == std::ifstream::traits_type::eof())
        return (std::cerr << "Error in database file: empty." << std::endl, true);
    std::getline(DB, line);
    if (line.compare("date,exchange_rate"))
        return (std::cerr << "Error in database file: incorrect format definition." << std::endl, true);
    while (std::getline(DB, line))
        if (isCSV())
            return (true);
    DB.clear();
    DB.seekg(sizeof("date,exchange_rate"), DB.beg);
    return (false);
}

bool    BitcoinExchange::isValidDate(const std::string date) const
{
    std::string aux;
    int         day;
    int         month;
    int         year;

    if (date.size() != 10 || date.at(4) != '-' || date.at(7) != '-')
        return (true);
    for (std::size_t i = 0; i < date.size(); i++)
        if ((i != 4 && i != 7) && !std::isdigit(date.at(i)))
            return (true);
    aux = date.substr(8, 2);
    day = atoi(aux.c_str());
    if (day < 0 || day > 31)
        return (true);
    aux = date.substr(5, 2);
    month = atoi(aux.c_str());
    if (month < 0 || month > 12 || (month == 2 && day > 29)
        || ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31))
        return (true);
    aux = date.substr(0, 4);
    year = atoi(aux.c_str());
    if (year < 1 || year > 2025 || (year == 2025
        && ((month > 6) || (month == 6 && day > 26))))
        return (true);
    return (false);
}

int     BitcoinExchange::countChar(const std::string str, char c) const
{
    int res = 0;

    for (std::size_t i = 0; i < str.size(); i++)
        if (str.at(i) == c)
            res++;
    return (res);
}
