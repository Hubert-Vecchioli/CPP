/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:39:23 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/11 17:03:16 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): name_("No name")
{
	this->fstrm_.open(this->name_.c_str());
	if (!this->fstrm_.is_open())
	{
		throw BitcoinExchange::FileNotOpeningException();
		exit(1);
	}
	return ;
}

BitcoinExchange::BitcoinExchange(std::string name): name_(name)
{
	this->fstrm_.open(this->name_.c_str());
	if (!this->fstrm_.is_open())
	{
		throw BitcoinExchange::FileNotOpeningException();
		exit(1);
	}
	return ;
}
BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs)
{
	*this = rhs;
}

BitcoinExchange	& BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	// do a deep copy
}

void getHistoricalData(BitcoinExchange const &rhs)
{
	// open csv
	// eat tge csv data into a map
}
void getPortfolioValue(BitcoinExchange const &rhs)
{
	try
	{
		//loop on the input file
		//output or exceptions
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char* BitcoinExchange::FileNotOpeningException::what() const throw()
{
	return ("Error: could not open file.");
}

const char* BitcoinExchange::WrongInputException::what() const throw()
{
	return ("Error: could not open file.");
}

const char* BitcoinExchange::NegativeBitcoinQuantityException::what() const throw()
{
	return ("Error: not a positive number.");
}

const char* BitcoinExchange::TooLargeBitcoinQuantityException::what() const throw()
{
	return ("Error: too large a number.");
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Error: bad input.");
}