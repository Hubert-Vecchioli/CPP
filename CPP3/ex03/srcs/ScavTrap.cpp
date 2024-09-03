/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 07:49:05 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/03 16:14:13 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): isGuardGate_(false)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name_ = "No name";
	this->hitPoint_ = 100;
	this->energyPoint_ = 50;
	this->attackDamage_ = 20;
}


ScavTrap::ScavTrap( std::string name ): isGuardGate_(false)
{
	std::cout << "ScavTrap constructor called with name " << name << std::endl;
	this->name_ = name;
	this->hitPoint_ = 100;
	this->energyPoint_ = 50;
	this->attackDamage_ = 20;
}

ScavTrap::ScavTrap( ScavTrap const & src )
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs )
{
	if (this == &rhs)
		return (*this);
	std::cout << "ScavTrap operator = called" << std::endl;
	this->name_ = rhs.name_;
	this->hitPoint_ = rhs.hitPoint_;
	this->energyPoint_ = rhs.energyPoint_;
	this->attackDamage_ = rhs.attackDamage_;
	this->isGuardGate_ = rhs.isGuardGate_;
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called with name " << this->name_ << std::endl;
}

void	ScavTrap::guardGate( void )
{
	if (this->isGuardGate_ == false)
	{
		this->isGuardGate_ = true;
		std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode" << std::endl;
	}
	else
	{
		this->isGuardGate_ = false;
		std::cout << "ScavTrap " << this->name_ << " is not in Gate keeper mode anymore" << std::endl;
	}
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->energyPoint_ <= 0 || this->hitPoint_ <= 0)
	{
		std::cout << "ScavTrap " << this->name_ << " has not enough life/energy to attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name_ << " attacks " << target << ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
	this->energyPoint_--;
}
