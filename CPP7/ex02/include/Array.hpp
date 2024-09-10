/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:56:00 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 14:18:22 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>

template<typename T>
class Array
{
	private:
		T		*array_;
		unsigned int	size_;

	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &rhs);
		~Array(void);
		Array<T> &operator=(Array const &rhs);
		T &operator[](unsigned int i);

		unsigned int size(void) const;
		
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif