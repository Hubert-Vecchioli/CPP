/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:32:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 13:54:48 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA( std::string name,  Weapon &weapon): name_(name), weapon_(weapon)
{	
	std::cout << this->name_ << " is being constructed with a " << this->weapon_.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this->name_ << " is being deleted" << std::endl;
}
void HumanA::attack( void )
{
	std::cout << this->name_ << " attacks with their " << this->weapon_.getType() << std::endl;
}
