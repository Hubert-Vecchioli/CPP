/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:07:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/01 22:49:18 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
//#include <string>

int	main(void) {
	std::string trapName0 = "Obi-wan";
	std::string trapName1 = "Anakin";

	ClapTrap	clap_trap0(trapName0);
	ClapTrap	clap_trap1(trapName1);

	clap_trap0.beRepaired(0);
	for (int i = 0; i < 9; i++) {
		clap_trap0.attack(trapName1);
		clap_trap1.takeDamage(0);
	}
	clap_trap0.attack(trapName1);
	clap_trap1.takeDamage(0);
	clap_trap1.beRepaired(4);
	clap_trap1.attack(trapName0);
	clap_trap0.takeDamage(0);
	clap_trap0.beRepaired(5000);
	clap_trap1.beRepaired(5000);
	clap_trap1.attack(trapName1);
	clap_trap1.takeDamage(0);
	clap_trap1.beRepaired(5000);
	clap_trap1.takeDamage(0);
	return (0);
}