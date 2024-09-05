/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:07:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 11:34:10 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	jedi("Obi-wan");
	ScavTrap	sith("Anakin");
	FragTrap	droid("C3PO");
	DiamondTrap	diamond("Yoda");

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
	diamond.whoAmI();
	diamond.display_infos();
	diamond.attack("Anakin");
	return (0);
}