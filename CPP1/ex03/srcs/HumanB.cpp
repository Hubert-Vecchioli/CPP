/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:32:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 13:55:24 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(  std::string name  ): name_(name)
{	
	std::cout << this->name_ << " is being constructed without any weapon" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->name_ << " is being deleted" << std::endl;
}
void HumanB::attack( void )
{
	std::cout << this->name_ << " attacks with their " << this->weapon_->getType() << std::endl;
}

void HumanB::setWeapon( Weapon &weapon )
{
	this->weapon_ = &weapon;
}
