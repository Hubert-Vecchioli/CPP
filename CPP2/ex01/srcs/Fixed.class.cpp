/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:45:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/29 14:12:24 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void): intValue_(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int intInput)
{
	std::cout << "Int constructor called" << std::endl;
	this->intValue_ = intInput << this->numBits_;
}

Fixed::Fixed(const float floatInput)
{
	std::cout << "Float constructor called" << std::endl;
	this->intValue_ = roundf(floatInput * (1 << this->numBits_));
}

Fixed::Fixed(Fixed const & fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return(this->intValue_);
}

void Fixed::setRawBits( int const raw )
{
	this->intValue_ = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)this->intValue_ / (1 << this->numBits_);
}

int Fixed::toInt( void ) const
{
	return this->intValue_ >> this->numBits_;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}