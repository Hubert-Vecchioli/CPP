/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:32:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 13:53:15 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "A new Zombie is being constructed" << std::endl;
}

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

void Zombie::setName( std::string name )
{
	this->name_ = name;
}