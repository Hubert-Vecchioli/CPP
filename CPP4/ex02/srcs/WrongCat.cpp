/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:50:31 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 08:16:53 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type_= "WrongCat";
	std::cout << "WrongCat default constructor called of type:" << this->type_ << std::endl;
}

WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "WrongCat operator = called on a " << rhs.type_ << std::endl;
	this->type_ = rhs.type_;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called " << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "[WrongCat noise]: Meeow" << std::endl;
}
