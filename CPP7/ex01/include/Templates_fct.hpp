/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates_fct.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:34:49 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 12:19:35 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_FCT_HPP
 # define TEMPLATES_FCT_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, unsigned int length, F function)
{
	for (unsigned int i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

template <typename W>
void print_info(W & number)
{
	std::cout << "[" << number << "] " << std::endl;
	return ;
}

template <typename V>
void addOne(V & number)
{
	number += 1;
	return ;
}

#endif