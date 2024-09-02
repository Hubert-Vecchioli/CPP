/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:32:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 10:26:08 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie( std::string name ): name_(name)
{
	std::cout << this->name_ << " is being constructed" << std::endl;

}

Zombie::~Zombie(void)
{
	std::cout << this->name_ << " is being erased from Earth..." << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}