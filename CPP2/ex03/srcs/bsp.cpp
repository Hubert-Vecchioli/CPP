/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 08:01:41 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/01 00:27:48 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

static Fixed ft_get_triangle_area(Point const a, Point const b, Point const c)
{
	return Fixed((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2).abs();
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area_abc = ft_get_triangle_area(a, b, c);
	Fixed	area_abp = ft_get_triangle_area(a, b, point);
	Fixed	area_acp = ft_get_triangle_area(a, c, point);
	Fixed	area_bcp = ft_get_triangle_area(b, c, point);
	return (area_abc == (area_abp + area_acp + area_bcp) && area_abp > 0 && area_acp > 0 && area_bcp > 0);
}