/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:59:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 22:04:26 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int intValue_;
	static const int numBits_ = 8;
public:
	Fixed(void);
	Fixed(const int intInput);
	Fixed(const float floatInput);
	Fixed(Fixed const & fixed);
	~Fixed(void);

	Fixed abs(void) const;
	Fixed & operator =(Fixed const & rhs);
	bool operator>(Fixed const & rhs) const;
	bool operator<(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;
	bool operator==(Fixed const & rhs) const;
	Fixed operator+(Fixed const & rhs) const;
	Fixed operator-(Fixed const & rhs) const;
	Fixed operator*(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;

	Fixed operator++(int);
	Fixed operator--(int);
	Fixed & operator++(void);
	Fixed & operator--(void);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	static Fixed const & min(Fixed const & fixed_1, Fixed const & fixed_2);
	static Fixed const & max(Fixed const & fixed_1, Fixed const & fixed_2);
	static Fixed & min(Fixed & fixed_1, Fixed & fixed_2);
	static Fixed & max(Fixed & fixed_1, Fixed & fixed_2);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif