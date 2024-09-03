/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/03 16:14:07 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name_ = "No name";
	this->hitPoint_ = 100;
	this->energyPoint_ = 100;
	this->attackDamage_ = 30;
}


FragTrap::FragTrap( std::string name )
{
	std::cout << "FragTrap constructor called with name " << name << std::endl;
	this->name_ = name;
	this->hitPoint_ = 100;
	this->energyPoint_ = 100;
	this->attackDamage_ = 30;
}

FragTrap::FragTrap( FragTrap const & src )
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs )
{
	if (this == &rhs)
		return (*this);
	std::cout << "FragTrap operator = called" << std::endl;
	this->name_ = rhs.name_;
	this->hitPoint_ = rhs.hitPoint_;
	this->energyPoint_ = rhs.energyPoint_;
	this->attackDamage_ = rhs.attackDamage_;
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called with name " << this->name_ << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->name_ << " is requesting a high five" << std::endl;
}