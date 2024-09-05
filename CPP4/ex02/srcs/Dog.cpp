/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:13:25 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 08:39:18 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type_= "Dog";
	std::cout << "Dog default constructor called of type:" << this->type_ << std::endl;
	this->brain_ = new Brain();
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain_ = new Brain();
	*this = src;
}

Dog & Dog::operator=(Dog const & rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Dog operator = called on a " << rhs.type_ << std::endl;
	this->type_ = rhs.type_;
	this->brain_->setIdeas(rhs.brain_->getIdeas());
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called " << std::endl;
	delete this->brain_;
}

void Dog::makeSound(void) const
{
	std::cout << "[Dog noise]: Baark" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (this->brain_);
}
