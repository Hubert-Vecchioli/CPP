/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 07:45:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 22:04:38 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed x_;
	Fixed y_;
public:
	Point(void);
	Point(const float x, const float y);
	Point(Point const & point);
	~Point(void);
	
	Point & operator=(Point const & rhs);
	Fixed getX( void ) const;
	Fixed getY( void ) const;
};

#endif