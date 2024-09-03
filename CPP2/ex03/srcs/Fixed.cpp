/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:45:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 22:07:38 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): intValue_(0)
{
}
Fixed::Fixed(const int intInput)
{
	this->intValue_ = intInput << this->numBits_;
}

Fixed::Fixed(const float floatInput)
{
	this->intValue_ = roundf(floatInput * (1 << this->numBits_));
}

Fixed::Fixed(Fixed const & fixed)
{
	*this = fixed;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	this->setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
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

bool Fixed::operator>(Fixed const & rhs) const
{
	return (this->intValue_ > rhs.intValue_);
}

bool Fixed::operator<(Fixed const & rhs) const
{
	return (this->intValue_ < rhs.intValue_);
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	return (this->intValue_ >= rhs.intValue_);
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	return (this->intValue_ <= rhs.intValue_);
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	return (this->intValue_ != rhs.intValue_);
}

bool Fixed::operator==(Fixed const & rhs) const
{
	return (this->intValue_ == rhs.intValue_);
}

Fixed Fixed::operator+(Fixed const & rhs) const
{	
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));	
}

Fixed Fixed::operator++(int)
{
	Fixed	temp_copy(*this);
	++(*this);
	return (temp_copy);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp_copy(*this);
	--(*this);
	return (temp_copy);
}

Fixed & Fixed::operator++(void)
{
	this->intValue_++;
	return (*this);
}

Fixed & Fixed::operator--(void)
{
	this->intValue_--;
	return (*this);
}

Fixed const & Fixed::min(Fixed const & fixed_1, Fixed const & fixed_2)
{
	if (fixed_1 < fixed_2)
		return (fixed_1);
	return (fixed_2);
}

Fixed const & Fixed::max(Fixed const & fixed_1, Fixed const & fixed_2)
{
	if (fixed_1 > fixed_2)
		return (fixed_1);
	return (fixed_2);
}

Fixed & Fixed::min(Fixed & fixed_1, Fixed & fixed_2)
{
	if (fixed_1 < fixed_2)
		return (fixed_1);
	return (fixed_2);
}

Fixed & Fixed::max(Fixed & fixed_1, Fixed & fixed_2)
{
	if (fixed_1 > fixed_2)
		return (fixed_1);
	return (fixed_2);
}

Fixed Fixed::abs(void) const
{
	Fixed zero;
	if(*this < zero)
		return (Fixed(this->toFloat() * (-1)));
	return (*this);
}