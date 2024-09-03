/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 07:52:21 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/03 12:02:57 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x_(0), y_(0)
{
}

Point::Point(const float x, const float y): x_(x), y_(y)
{
}

Point::Point(Point const & point): x_(point.x_), y_(point.y_)
{
}

Point::~Point(void)
{
	
}

Point & Point::operator=(Point const & rhs)
{
	this->x_ = rhs.x_;
	this->y_ = rhs.y_;
	return *this;
}

Fixed Point::getX( void ) const
{
	return this->x_;
}

Fixed Point::getY( void ) const
{
	return this->y_;
}
