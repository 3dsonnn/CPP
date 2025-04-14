/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:58:58 by efinda            #+#    #+#             */
/*   Updated: 2025/04/14 13:52:24 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// STATIC VARIABLES DEFINITIONS
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// GETTERS
int Account::checkAmount( void ) const { return (_amount); }

int	Account::getNbAccounts( void ) { return (_nbAccounts); }

int	Account::getTotalAmount( void ) { return (_totalAmount); }

int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }

int	Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }


// PUBLIC
Account::Account( int initial_deposit )
{
    _accountIndex = getNbAccounts();
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
        << "amount:" << checkAmount() << ";"
        << "created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
        << "amount:" << checkAmount() << ";"
        << "closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
        << "total:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit( int deposit )
{
    _amount += deposit;
    _nbDeposits++;
    
    _totalAmount += deposit;
    _totalNbDeposits++;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
        << "p_amount:" << checkAmount() - deposit << ";"
        << "deposit:" << deposit << ";"
        << "amount:" << checkAmount() << ";"
        << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    if (withdrawal > checkAmount())
    {
        std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << checkAmount() << ";"
            << "withdrawal:refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals++;

    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex << ";"
        << "p_amount:" << checkAmount() + withdrawal << ";"
        << "withdrawal:" << withdrawal << ";"
        << "amount:" << checkAmount() << ";"
        << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
    << "amount:" << checkAmount() << ";"
    << "deposits:" << _nbDeposits << ";"
    << "withdrawals:" << _nbWithdrawals << std::endl;
}

// PRIVATE
void Account::_displayTimestamp( void )
{
    char    buffer[20];

    std::time_t rawTime = std::time(NULL);
    std::tm *convertedTime = std::localtime(&rawTime);
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", convertedTime);
    std::cout << buffer;
}

Account::Account( void ) {}
