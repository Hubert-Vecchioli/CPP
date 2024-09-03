/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:59:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 22:03:18 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int rawBits_;
	static const int numBits_ = 8;
public:
	Fixed(void);
	Fixed(Fixed const & fixed);
	Fixed & operator =(Fixed const & rhs);
	~Fixed(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif