/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates_fct.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:34:49 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/09 15:45:29 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_FCT_HPP
# define TEMPLATES_FCT_HPP

#include <iostream>

template <typename T>
T const & min(T const & x, T const & y)
{
	return( x <= y ? x : y);
}

template <typename T>
T const & max(T const & x, T const & y)
{
	return( x >= y ? x : y);
}

template <typename T>
void swap(T & x, T & y)
{
	T temp = x;
	x = y;
	y = temp;
}

#endif