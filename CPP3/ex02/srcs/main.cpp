/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:07:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/03 16:05:48 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	jedi("Obi-wan");
	ScavTrap	sith("Anakin");
	FragTrap	droid("C3PO");

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
	droid.highFivesGuys();
	return (0);
}