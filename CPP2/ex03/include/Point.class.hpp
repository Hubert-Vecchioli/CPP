/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 07:45:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/30 08:27:25 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

#include "Fixed.class.hpp"

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