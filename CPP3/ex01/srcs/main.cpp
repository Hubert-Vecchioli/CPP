/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:07:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/03 08:35:49 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
//#include <string>

int	main(void) {
	std::string trapName0 = "Obi-wan";
	std::string trapName1 = "Anakin";

	ClapTrap	clap_trap0(trapName0);
	ScavTrap	scavtrap0(trapName1);

	scavtrap0.guardGate();
	clap_trap0.beRepaired(0);
	for (int i = 0; i < 9; i++) {
		clap_trap0.attack(trapName1);
		scavtrap0.takeDamage(0);
	}
	clap_trap0.attack(trapName1);
	scavtrap0.takeDamage(0);
	scavtrap0.beRepaired(4);
	scavtrap0.attack(trapName0);
	clap_trap0.takeDamage(0);
	clap_trap0.beRepaired(5000);
	scavtrap0.beRepaired(5000);
	scavtrap0.attack(trapName1);
	scavtrap0.takeDamage(0);
	scavtrap0.beRepaired(5000);
	scavtrap0.takeDamage(0);
	scavtrap0.guardGate();
	return (0);
}