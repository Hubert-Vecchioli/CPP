/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:39:23 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/12 15:02:17 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): name_("No name")
{
	this->fstrm_.open(this->name_.c_str());
	if (!this->fstrm_.is_open())
		throw FileNotOpeningException();
	this->getHistoricalPrices_();
}

BitcoinExchange::BitcoinExchange(std::string name): name_(name)
{
	this->fstrm_.open(this->name_.c_str());
	if (!this->fstrm_.is_open())
		throw FileNotOpeningException();
	this->getHistoricalPrices_();
}
BitcoinExchange::~BitcoinExchange(void)
{
	if (this->fstrm_.is_open())
		this->fstrm_.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs)
{
	*this = rhs;
	return ;
}

BitcoinExchange	& BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
		this->historicalPricesMap_ = rhs.historicalPricesMap_;
	return (*this);
}

double BitcoinExchange::convertDouble_(const std::string &input)
{
	std::stringstream ss(input);
    double result;
    ss >> result;
    if (ss.fail()) 
        throw std::runtime_error("Invalid input");
    return result;
}

int BitcoinExchange::convertInt_(const std::string &input)
{
	std::stringstream ss(input);
    int result;
    ss >> result;
    if (ss.fail())
        throw std::runtime_error("Invalid input");
    return result;
}

void BitcoinExchange::getHistoricalPrices_(void)
{
	std::string	line;
	std::ifstream historicalPricesFile("data.csv");

	if (!historicalPricesFile.is_open())
		throw NoHistoricalPricesException();
	std::getline(historicalPricesFile, line);
	if (line.compare("date,exchange_rate") != 0)
		throw InvalidHistoricalPricesFormatException();
	while (std::getline(historicalPricesFile, line))
	{
    	std::size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
        	throw InvalidHistoricalPricesFormatException();
    	std::string date = line.substr(0, commaPos);
    	std::string valueStr = line.substr(commaPos + 1);

    	double price;
		try
		{
			price = convertDouble_(valueStr);
		}
		catch (const std::exception &e)
		{
			throw InvalidHistoricalPricesFormatException();
		}
		this->historicalPricesMap_[date] = price;
	}
	if (this->historicalPricesMap_.empty())
		throw NoHistoricalPricesException();
	historicalPricesFile.close();
}
void BitcoinExchange::printPrices_(std::string date, double quantity)
{
	if (this->historicalPricesMap_.count(date))
		std::cout << date << " => " << quantity << " = " << this->historicalPricesMap_[date] * quantity << std::endl;
	else
	{
		std::map<std::string, double>::iterator it = this->historicalPricesMap_.upper_bound(date);
		if (it == this->historicalPricesMap_.begin())
			throw NoPreviousDateException();
		else
		{
			--it;
			std::cout << date << " => " << quantity << " = " << it->second * quantity << std::endl;
		}
	}
}


void BitcoinExchange::reviewDate_(std::string date) const
{
	time_t now = time(0);
	tm *current_date = localtime(&now);

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw InvalidDateException();
	int year = convertInt_(date.substr(0, 4));
	int month = convertInt_(date.substr(5, 2));
	int day = convertInt_(date.substr(8, 2));
	if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2000)
		throw InvalidDateException();
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		throw InvalidDateException();
	if (year > 1900 + current_date->tm_year)
		throw InvalidDateException();
	else if (year == 1900 + current_date->tm_year)
	{
		if (month > 1 + current_date->tm_mon)
			throw InvalidDateException();
		else if (month == 1 + current_date->tm_mon)
		{
			if (day > current_date->tm_mday)
				throw InvalidDateException();
		}
	}
}

void BitcoinExchange::reviewQuantity_(double quantity) const
{
	if (quantity < 0)
		throw NegativeBitcoinQuantityException();
	if (quantity > 1000)
		throw TooLargeBitcoinQuantityException();
	return ;
}

void BitcoinExchange::getPortfolioValue(void)
{
	std::string line;
	
	if (!this->fstrm_.is_open())
		throw FileNotOpeningException();
	std::getline(this->fstrm_, line);
	if (line.compare("date | value") != 0)
		throw InvalidHistoricalPricesFormatException();
	int count_row = 0;
	while (std::getline(this->fstrm_, line))
	{

		std::size_t linePos = line.find('|');
    	std::string date = line.substr(0, linePos - 1);
    	std::string valueStr = line.substr(linePos + 2);
		try
		{
    	double quantity = convertDouble_(valueStr);
		reviewDate_(date);
		reviewQuantity_(quantity);

		this->printPrices_(date, quantity);
		}
		catch (std::exception & e)
		{
			if (std::string(e.what()) == "Error: bad input.")
				std::cout << e.what() << " => " << date << std::endl;
			else
				std::cout << e.what() << std::endl;
		}
		count_row++;
	}
	if (count_row == 0)
		throw FileNotOpeningException();
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

const char* BitcoinExchange::InvalidHistoricalPricesFormatException::what() const throw()
{
	return ("Error: the historical prices have a wrong format.");
}

const char* BitcoinExchange::InvalidInputFormatException::what() const throw()
{
	return ("Error: the input has a wrong format, '|' is missing.");
}

const char* BitcoinExchange::NoHistoricalPricesException::what() const throw()
{
	return ("Error: there are no historical prices.");
}

const char* BitcoinExchange::NoPreviousDateException::what() const throw()
{
	return ("Error: there is no previous historical price.");
}

