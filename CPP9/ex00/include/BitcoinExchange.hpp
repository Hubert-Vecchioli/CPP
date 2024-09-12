/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:39:26 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/12 14:46:43 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <algorithm>
# include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		const std::string name_;
		std::ifstream fstrm_;
		std::map<std::string, double> historicalPricesMap_;
		BitcoinExchange(void);
		void getHistoricalPrices_(void);
		void printPrices_(std::string date, double price);
		void reviewDate_(std::string date) const;
		void reviewQuantity_(double quantity) const;
		static double convertDouble_(const std::string &input);
		static int convertInt_(const std::string &input);
	public:
		BitcoinExchange(std::string name);
		BitcoinExchange(BitcoinExchange const &rhs);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);

		void getPortfolioValue(void);

		class FileNotOpeningException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class WrongInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NegativeBitcoinQuantityException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class TooLargeBitcoinQuantityException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidHistoricalPricesFormatException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoHistoricalPricesException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidInputFormatException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoPreviousDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif