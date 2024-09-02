/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:59:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/29 09:07:35 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

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
	Fixed & operator =(Fixed const & rhs);
	~Fixed(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif