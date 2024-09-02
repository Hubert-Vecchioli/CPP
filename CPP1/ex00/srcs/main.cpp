/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:08:13 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/22 09:57:44 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.class.hpp>

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

int main(void)
{
    Zombie zombie1("Albert");
    Zombie *zombie2 = newZombie("Paul");
	zombie1.announce();
    zombie2->announce();
    delete zombie2;
    randomChump("Bernard");
    return 0;
}