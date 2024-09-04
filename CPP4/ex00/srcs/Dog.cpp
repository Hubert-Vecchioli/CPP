/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:13:25 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/04 17:58:51 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type_= "Dog";
	std::cout << "Dog default constructor called of type:" << this->type_ << std::endl;
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog operator = called on a " << rhs.type_ << std::endl;
	this->type_ = rhs.type_;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called " << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "[Dog noise]: Baark" << std::endl;
}