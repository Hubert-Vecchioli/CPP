/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:39:26 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/11 15:39:58 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::string name_;
		std::ifstream fstrm_;
		//une map
		BitcoinExchange(void);
	public:
		BitcoinExchange(std::string name);
		BitcoinExchange(BitcoinExchange const &rhs);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);

		void getHistoricalData(BitcoinExchange const &rhs);
		void getPortfolioValue(BitcoinExchange const &rhs);

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
};

#endif