/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:39 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 08:16:19 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type): type_(type)
{
	std::cout << "AAnimal default constructor called with type;" << this->type_ << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "AAnimal operator = called on a " << rhs.type_ << std::endl;
	this->type_ = rhs.type_;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called " << std::endl;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "AAnimal sound" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->type_);
}
