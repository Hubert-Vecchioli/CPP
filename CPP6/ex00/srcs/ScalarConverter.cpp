/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:15:18 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/09 11:38:00 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const std::string &input)
{
	(void)input;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return (*this);
}

bool ScalarConverter::hasDisplayableCharacters_(std::string &input)
{
	for (size_t i = 0; i < input.length(); ++i)
	{
        if (static_cast<char>(input[i]) < 32 || static_cast<char>(input[i]) > 126)
			return (false);
    }
	return (true);
}
bool ScalarConverter::isChar_(std::string &input)
{
	if (input.length() != 1)
		return (false);
	if (std::isdigit(input[0]))
		return (false);
	return (true);
}

bool ScalarConverter::isInt_(std::string &input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	for (size_t j = i; j < input.length(); j++)
	{
		if (!std::isdigit(input[j]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::isFloat_(std::string &input)
{
	int	i;
	int	dot;
	int	nb_num;

	if (input[input.length() - 1] != 'f')
		return (false);
	if (!input.compare("-inff") || !input.compare("+inff") \
		|| !input.compare("nanf"))
		return (true);
	i = 0;
	dot = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	nb_num = 0;
	for (size_t j = i; j < input.length() - 1; j++)
	{
		if (input[j] == '.')
			dot++;
		if (std::isdigit(input[j]))
			nb_num++;
	}
	if (!nb_num || dot > 1 || i + dot + nb_num != static_cast<int>(input.length()) - 1)
		return (false);
	return (true);
}

bool ScalarConverter::isDouble_(std::string &input)
{
	int	i;
	int	dot;
	int	nb_num;

	if (!input.compare("-inf") || !input.compare("+inf") \
		|| !input.compare("nan"))
		return (true);
	i = 0;
	dot = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	nb_num = 0;
	for (size_t j = i; j < input.length(); j++)
	{
		if (input[j] == '.')
			dot++;
		if (std::isdigit(input[j]))
			nb_num++;
	}
	if (!nb_num || dot > 1 || i + dot + nb_num != static_cast<int>(input.length()))
		return (false);
	return (true);
}

 int ScalarConverter::getType_(std::string &input)
{
	if (isChar_(input))
		return 0;
	if (isInt_(input))
		return 1;
	if (isFloat_(input))
		return 2;
	if (isDouble_(input))
		return 3;
	return 4;
}
char ScalarConverter::convertChar_(const std::string &input)
{
	int		ret;
	std::istringstream	ss(input);
	ss >> ret;
	return (static_cast<char>(ret));
}

int ScalarConverter::convertInt_(const std::string &input)
{
	std::stringstream ss(input);
    int result;
    ss >> result;
    if (ss.fail()) {
        throw std::runtime_error("Invalid input");
    }
    return result;
}

float ScalarConverter::convertFloat_(const std::string &input)
{
	std::stringstream ss(input);
    float result;
    ss >> result;
    if (ss.fail()) {
        throw std::runtime_error("Invalid input");
    }
    return result;
}

double ScalarConverter::convertDouble_(const std::string &input)
{
	std::stringstream ss(input);
    double result;
    ss >> result;
    if (ss.fail()) {
        throw std::runtime_error("Invalid input");
    }
    return result;
}

void ScalarConverter::printChar_(std::string &input, int type)
{
	double	d;
	char	c;

	if (type == 0)
	{
		if (!std::isprint(static_cast<int>(input.at(0))))
			std::cout << "char: impossible to display" << std::endl;
		else
			std:: cout << "char: '" << input << "'" << std::endl;
		return ;
	}
	try
	{
		if (!input.compare("-inff") || !input.compare("+inff") \
		|| !input.compare("nanf") || !input.compare("-inf") \
		|| !input.compare("+inf") || !input.compare("nan"))
			throw std::exception();
		if (type != 2)
		{
			c = convertChar_(input);
			d = convertDouble_(input);
		}
		else
		{
			c = convertChar_(input.substr(0, input.length() - 1));
			d = convertDouble_(input.substr(0, input.length() - 1));
		}
	} catch (std::exception &e) {
		std::cout << "char: impossible to display" << std::endl;
		return ;
	}
	if (d < 32 || d > 126)
		std::cout << "char: impossible to display" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt_(std::string &input, int type)
{
	double	d;
	int		i;

	try {
		if (!input.compare("-inff") || !input.compare("+inff") \
		|| !input.compare("nanf") || !input.compare("-inf") \
		|| !input.compare("+inf") || !input.compare("nan"))
			throw std::exception();
		if (type != 2 && type != 0)
		{
			i = convertInt_(input);
			d = convertDouble_(input);
		}
		else if (type == 2)
		{
			i = convertInt_(input.substr(0, input.length() - 1));
			d = convertDouble_(input.substr(0, input.length() - 1));
		}
		else
		{
			i = static_cast<int>(input.at(0));
			d = static_cast<double>(input.at(0));
		}
	} 
	catch (std::exception &e) {
		std::cout << "int: impossible to display" << std::endl;
		return ;
	}
	if (d < -2147483648 || d > 2147483647)
		std::cout << "int: impossible to display" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat_(std::string &input, int type)
{
	float	f;

	if (!input.compare("-inff") || !input.compare("+inff") \
		|| !input.compare("nanf") || !input.compare("-inf") \
		|| !input.compare("+inf") || !input.compare("nan"))
	{
		if (!input.compare("+inf") || !input.compare("-inf") || !input.compare("nan"))
			std::cout << "float: " << input << "f" << std::endl;
		else
			std::cout << "float: " << input << std::endl;
		return ;
	}
	try {
		if (type != 2 && type != 0)
			f = convertFloat_(input);
		else if (type == 2)
			f = convertFloat_(input.substr(0, input.length() - 1));
		else
			f = static_cast<float>(input.at(0));
	}
	catch (std::exception &e) {
		std::cout << "float: impossible to display" << std::endl;
		return ;
	}
	if (f < -FLT_MAX || f > FLT_MAX)
	{
		std::cout << "float: impossible to display" << std::endl;
		return ;
	}
	if (f == static_cast<int>(f))
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		return ;
	}
	std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble_(std::string &input, int type)
{
	double	d;

	if (!input.compare("-inff") || !input.compare("+inff") \
		|| !input.compare("nanf") || !input.compare("-inf") \
		|| !input.compare("+inf") || !input.compare("nan"))
	{
		if (!input.compare("+inf") || !input.compare("-inf") || !input.compare("nan"))
			std::cout << "double: " << input << std::endl;
		else
			std::cout << "double: " << input.substr(input.length() - 1) << std::endl;
		return ;
	}
	try {
		if (type != 2 && type != 0)
			d = convertDouble_(input);
		else if (type == 2)
			d = convertDouble_(input.substr(0, input.length() - 1));
		else
			d = static_cast<double>(input.at(0));
	} catch (std::exception &e) {
		std::cout << "double: impossible to display" << std::endl;
		return ;
	}
	if (d < -DBL_MAX || d > DBL_MAX)
	{
		std::cout << "double: impossible to display" << std::endl;
		return ;
	}
	if (d == static_cast<int>(d))
	{
		std::cout << "double: " << d << ".0" << std::endl;
		return ;
	}
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string &input)
{
	int	type;
	if (input.length() == 0)
		throw ScalarConverter::EmptyInputException();
	type = getType_(input);
	if (type == 4)
		throw ScalarConverter::UnkownTypeException();
	printChar_(input, type);
	printInt_(input, type);
	printFloat_(input, type);
	printDouble_(input, type);
}

const char * ScalarConverter::NonDisplayableCharactersException::what() const throw()
{
	return ("Error: The input has non displayable characters");
}

const char * ScalarConverter::UnkownTypeException::what() const throw()
{
	return ("Error: the input type is be not identified");
}

const char * ScalarConverter::EmptyInputException::what() const throw()
{
	return ("Error: the input string is empty");
}