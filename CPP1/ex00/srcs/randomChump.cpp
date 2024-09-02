/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:08:08 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 10:26:12 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie newZ = Zombie( name );
	newZ.announce();
	return ;
}