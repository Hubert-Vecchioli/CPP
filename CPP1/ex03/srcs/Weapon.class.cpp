/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:32:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/23 14:51:57 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.class.hpp"

Weapon::Weapon( std::string type )
{	
	this->setType(type);
	std::cout << this->type_ << " is being constructed" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << this->type_ << " is being deleted" << std::endl;
}
std::string const &Weapon::getType(void) const
{
	return(this->type_);
}

void Weapon::setType( std::string type )
{
	this->type_ = type;
}
