/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:08:11 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 13:53:22 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}