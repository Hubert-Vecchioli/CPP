/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:15:11 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/09 08:09:37 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cfloat>
# include <limits.h>
# include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const std::string &input);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);

		ScalarConverter &operator=(ScalarConverter const &src);
		static int getType_(std::string &input);
		static bool hasDisplayableCharacters_(std::string &input);
		static bool isChar_(std::string &input);
		static bool isInt_(std::string &input);
		static bool isFloat_(std::string &input);
		static bool isDouble_(std::string &input);
		static void printChar_(std::string &input, int type);
		static void printInt_(std::string &input, int type);
		static void printFloat_(std::string &input, int type);
		static void printDouble_(std::string &input, int type);
		static char convertChar_(const std::string &input);

	public:
		static void convert(std::string &input);

		class	NonDisplayableCharactersException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	UnkownTypeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	EmptyInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif