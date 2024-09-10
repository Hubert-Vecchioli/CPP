/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:46:25 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 17:03:05 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

class MissingValueException : public std::exception
{
	public:
		virtual const char	*what(void) const throw();
};

template<typename T>
void easyfind(T & container, int targer_value)
{
	typename T::iterator it;
	
	it = container.find(targer_value);
	if (it == container.end())
		throw std::exception();
	std::cout << "Value found: " << *it << std::endl;
}

#endif