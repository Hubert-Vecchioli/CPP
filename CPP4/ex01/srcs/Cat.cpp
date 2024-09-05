/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:04:26 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 08:41:48 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type_= "Cat";
	std::cout << "Cat default constructor called of type:" << this->type_ << std::endl;
	this->brain_ = new Brain();
}

Cat::Cat(Cat const & src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain_ = new Brain();
	*this = src;
}

Cat & Cat::operator=(Cat const & rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Cat operator = called on a " << rhs.type_ << std::endl;
	this->brain_->setIdeas(rhs.brain_->getIdeas());
	this->type_ = rhs.type_;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called " << std::endl;
	delete this->brain_;
}

void Cat::makeSound(void) const
{
	std::cout << "[Cat noise]: Meeow" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (this->brain_);
}
