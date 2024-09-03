/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:07:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/03 13:32:20 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) 
{
	ClapTrap	jedi("Obi-Wan");

	jedi.attack("Anakin");
	jedi.attack("Anakin");
	jedi.attack("Anakin");
	jedi.attack("Anakin");
	jedi.attack("Anakin");
	jedi.attack("Anakin");
	jedi.attack("Anakin");
	jedi.attack("Anakin");
	jedi.attack("Anakin");
	jedi.attack("Anakin");
	jedi.attack("Anakin");
	jedi.takeDamage(9);
	jedi.attack("Anakin");
	jedi.takeDamage(1);
	jedi.attack("Anakin");
	jedi.beRepaired(10);
	return (0);
}