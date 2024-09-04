/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/03 23:47:31 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name_ = this->ScavTrap::name_;
	this->ClapTrap::name_ = this->name_ + "_clap_name";
	this->hitPoint_ = this->FragTrap::hitPoint_;
	this->energyPoint_ = this->ScavTrap::energyPoint_;
	this->attackDamage_ = this->FragTrap::attackDamage_;
}


DiamondTrap::DiamondTrap( std::string name ): name_(name)
{
	std::cout << "DiamondTrap constructor called with name " << name << std::endl;
	this->ClapTrap::name_ = this->name_ + "_clap_name";
	this->hitPoint_ = this->FragTrap::hitPoint_;
	this->energyPoint_ = this->ScavTrap::energyPoint_;
	this->attackDamage_ = this->FragTrap::attackDamage_;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src )
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if (this == &rhs)
		return (*this);
	std::cout << "DiamondTrap operator = called" << std::endl;
	this->name_ = rhs.name_;
	this->hitPoint_ = rhs.hitPoint_;
	this->energyPoint_ = rhs.energyPoint_;
	this->attackDamage_ = rhs.attackDamage_;
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called with name " << this->name_ << std::endl;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap " << this->name_ << ", is the son of " << ClapTrap::name_ << std::endl;
}