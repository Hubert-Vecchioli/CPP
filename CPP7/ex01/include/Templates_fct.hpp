/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates_fct.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:34:49 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/09 16:13:05 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_FCT_HPP
# define TEMPLATES_FCT_HPP

#include <iostream>

template <typename T, typename U, typename V>
void iter(T *array, unsigned int lenght, U f(V))
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		addr[i] = f(addr[i]);
		i++;
	}
}

template <typename T>
void	addOne(T & number)
{
	number += 1;
	return ;
}

#endif