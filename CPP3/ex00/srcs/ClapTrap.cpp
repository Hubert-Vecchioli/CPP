/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:45:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/03 13:44:16 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name_("No name"), hitPoint_(10), energyPoint_(10), attackDamage_(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name_(name), hitPoint_(10), energyPoint_(10), attackDamage_(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "ClapTrap operator = called" << rhs.name_ << std::endl;
	this->name_ = rhs.name_;
	this->hitPoint_ = rhs.hitPoint_;
	this->energyPoint_ = rhs.energyPoint_;
	this->attackDamage_ = rhs.attackDamage_;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called with " << this->name_ << std::endl;
}


void	ClapTrap::attack(std::string const & target)
{
	if (this->energyPoint_ <= 0 || this->hitPoint_ <= 0)
	{
		std::cout << "ClapTrap " << this->name_ << " has not enough life/energy to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
	this->energyPoint_--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint_ <= 0)
	{
		std::cout << "ClapTrap " << this->name_ << " has already 0 hit points" << std::endl;
		return ;
	}
	if (this->hitPoint_ - amount < 0)
		this->hitPoint_ = 0;
	else
		this->hitPoint_ -= amount;
	std::cout << "ClapTrap " << this->name_ << " takes " << amount << " points of damage! He has now " << this->hitPoint_ << " hit points." << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint_ <= 0 || this->hitPoint_ <= 0)
	{
		std::cout << "ClapTrap " << this->name_ << " has not enough life/energy to be repaired" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name_ << " repaired " << amount << " points. " << this->name_ << " has now " << this->hitPoint_ + amount << " hit points." << std::endl;
	this->hitPoint_ += amount;
	this->energyPoint_--;
}
