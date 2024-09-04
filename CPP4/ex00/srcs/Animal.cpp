/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:39 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/04 17:36:57 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type): type_(type)
{
	std::cout << "Animal default constructor called with type;" << this->type_ << std::endl;
}

Animal::Animal(Animal const & src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal & Animal::operator=(Animal const & rhs)
{
	std::cout << "Animal operator = called on a " << rhs.type_ << std::endl;
	this->type_ = rhs.type_;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called " << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type_);
}
