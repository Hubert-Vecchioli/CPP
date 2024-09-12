/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:04:53 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/12 16:23:40 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cmath>

class RPN
{
	private:
		std::stack<int> _stack;
		static bool isOperator_(char c);
		RPN(void);
	public:
		RPN(std::string input);
		RPN(RPN const &rhs);
		~RPN(void);

		RPN &operator=(RPN const &rhs);

		void	calculate(void);

		// Exceptions
		class InvalidExpressionException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class DivideByZeroException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif