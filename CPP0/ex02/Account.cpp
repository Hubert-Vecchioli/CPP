/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:32:32 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 12:17:02 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ): 
_accountIndex(_nbAccounts),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0) 
{
	Account::_nbAccounts += 1;
	Account::_totalAmount += _amount;
	this->_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts -= 1;
	Account::_totalAmount -= _amount;
	this->_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t now = time(0);
    std::tm *date = localtime(&now);
	std::cout << "[";
	std::cout << std::setfill('0') << 1900 + date->tm_year;
	std::cout << std::setfill('0') << std::setw(2) << 1 + date->tm_mon;
	std::cout << std::setfill('0') << std::setw(2) << date->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << date->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << date->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << date->tm_sec;
	std::cout << "]";
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	Account::_nbDeposits++;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	Account::_amount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "nb_deposit:" << Account::_nbDeposits << std::endl;
	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	else 
	std::cout << withdrawal << ";" << std::flush;
	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "nb_deposit:" << Account::_nbDeposits << std::endl;
	return true;
}

int	Account::checkAmount( void ) const
{
	return Account::_amount;	
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout	<< "index:" << Account::_accountIndex << ";"
				<< "amount:" << Account::_amount << ";"
				<< "deposits:" << Account::_nbDeposits << ";"
				<< "withdrawals:" << Account::_nbWithdrawals << std::endl;
}

