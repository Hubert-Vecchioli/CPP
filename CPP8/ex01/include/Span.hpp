/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:21:23 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 17:03:21 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int n_;
		std::vector<int>v_;
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);
		Span &operator=(Span const &src);
		
		void addNumber(int n);
		void addRange(std::vector<int>vector_to_add);
		int shortestSpan(void);
		int longestSpan(void);
		
		class MissingSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class ReachedMaxSizeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};				
};

#endif