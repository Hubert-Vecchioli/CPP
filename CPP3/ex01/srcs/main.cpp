/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:07:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/03 13:46:35 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
//#include <string>

int	main(void)
{
	ClapTrap	jedi("Obi-wan");
	ScavTrap	sith("Anakin");

	jedi.attack("Anakin");
	sith.takeDamage(jedi.getAttackDamage());
	sith.attack("Obi-wan");
	jedi.takeDamage(sith.getAttackDamage());
	jedi.attack("Anakin");
	sith.takeDamage(jedi.getAttackDamage());
	sith.guardGate();
	sith.attack("Obi-wan");
	jedi.takeDamage(sith.getAttackDamage());
	jedi.attack("Anakin");
	sith.takeDamage(jedi.getAttackDamage());
	sith.guardGate();
	return (0);
}