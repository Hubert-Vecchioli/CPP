/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:06:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/12 15:40:47 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{	
}

RPN::RPN(std::string input)
{	
	bool prevIsDigit = false;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]))
		{
			if (prevIsDigit)
				throw InvalidExpressionException();
			int number = input[i] - '0';
			this->_stack.push(number);
			prevIsDigit = true;
		}
		else if (isOperator_(input[i]))
		{
			if (this->_stack.size() < 2)
				throw InvalidExpressionException();
			int a = this->_stack.top();
			this->_stack.pop();
			int b = this->_stack.top();
			this->_stack.pop();
			switch(input[i])
			{
			case '+':
				this->_stack.push(b + a);
				break;
			case '-':
				this->_stack.push(b - a);
				break;
			case '*':
				this->_stack.push(b * a);
				break;
			case '/':
				if (!a)
					throw DivideByZeroException();
				this->_stack.push(b / a);
				break ;
			default:
				throw InvalidExpressionException();
			}
			prevIsDigit = false;
		}
		else if (!iswspace(input[i]))
			throw InvalidExpressionException();
		else 
			prevIsDigit = false;
	}
	if (this->_stack.size() != 1)
		throw InvalidExpressionException();
	std::cout << this->_stack.top() << std::endl;
}

RPN::RPN(RPN const &rhs)
{
	*this = rhs;
	return ;
}

RPN::~RPN(void)
{
}

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		this->_stack = rhs._stack;
	return (*this);
}

bool RPN::isOperator_(char c) 
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

const char* RPN::InvalidExpressionException::what() const throw()
{
	return ("Error");
}

const char* RPN::InvalidInputException::what() const throw()
{
	return ("Error: Invalid input");
}

const char* RPN::DivideByZeroException::what() const throw()
{
	return ("Error: Trying to divide by 0");
}