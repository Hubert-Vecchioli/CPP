/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:39:23 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/12 08:12:12 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

	// private:
	// 	std::string name_;
	// 	std::ifstream fstrm_;
	// 	std::map<std::string, double> historicalPrices_,
	// 	BitcoinExchange(void);
	// 	void getHistoricalPrices(void);
	// 	void printPrices(void) const;
	// 	void reviewDate(void) const;
	// 	void reviewDate(void) const;
	// public:
	// 	BitcoinExchange(std::string name);
	// 	BitcoinExchange(BitcoinExchange const &rhs);
	// 	~BitcoinExchange(void);
	// 	BitcoinExchange	&operator=(BitcoinExchange const &rhs);


BitcoinExchange::BitcoinExchange(void): name_("No name")
{
	this->fstrm_.open(this->name_.c_str());
	if (!this->fstrm_.is_open())
	{
		throw BitcoinExchange::FileNotOpeningException();
	}
	return ;
}

BitcoinExchange::BitcoinExchange(std::string name): name_(name)
{
	this->fstrm_.open(this->name_.c_str());
	if (!this->fstrm_.is_open())
	{
		throw BitcoinExchange::FileNotOpeningException();
		return ;
	}
	this->getHistoricalPrices();
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

double BitcoinExchange::convertDouble_(const std::string &input)
{
	std::stringstream ss(input);
    double result;
    ss >> result;
    if (ss.fail()) {
        throw std::runtime_error("Invalid input");
    }
    return result;
}

void BitcoinExchange::getHistoricalPrices(void)
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
		try {
			price = convertDouble_(valueStr);
		} catch (const std::exception &e) {
			throw InvalidHistoricalPricesFormatException();
		}
		this->historicalPricesMap_[date] = price;
	}
	if (this->historicalPricesMap_.empty())
		throw NoHistoricalPricesException();
	
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

const char* BitcoinExchange::InvalidHistoricalPricesFormatException::what() const throw()
{
	return ("Error: the historical prices have a wrong format.");
}

const char* BitcoinExchange::NoHistoricalPricesException::what() const throw()
{
	return ("Error: there are no historical prices.");
}

