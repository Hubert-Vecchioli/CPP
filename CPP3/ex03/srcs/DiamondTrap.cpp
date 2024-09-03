/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/03 17:12:52 by hvecchio         ###   ########.fr       */
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
	this->attackDamage_ = this->FragTrap::;
}


DiamondTrap::DiamondTrap( std::string name )
{
	std::cout << "DiamondTrap constructor called with name " << name << std::endl;
	this->name_ = name;
	this->hitPoint_ = 100;
	this->energyPoint_ = 500;
	this->attackDamage_ = 20;
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

void	DiamondTrap::highFivesGuys( void )
{
	std::cout << "DiamondTrap " << this->name_ << " is requesting a high five" << std::endl;
}